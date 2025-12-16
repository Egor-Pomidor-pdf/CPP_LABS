#include "fight_thread.h"
#include "fight_visitor.h"
#include "observer.h"
#include <random>
#include <thread>

void fight_thread(GameState &state,
                  const std::shared_ptr<IFightObserver> &textObserver,
                  const std::shared_ptr<IFightObserver> &fileObserver)
{
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dice(1, 6);

    while (state.running)
    {
        FightTask task;

        // --- получение задачи боя ---
        {
            std::lock_guard lock(state.fight_mutex);
            if (state.fights.empty())
                continue;

            task = state.fights.front();
            state.fights.pop();
        }

        auto attacker = task.attacker;
        auto defender = task.defender;

        if (!attacker->isAlive() || !defender->isAlive())
            continue;

        // --- проверка дистанции убийства ---
        double dist = attacker->distanceTo(defender);
        bool attackerCanKill = dist <= attacker->getKillDistance();
        bool defenderCanKill = dist <= defender->getKillDistance();

        // --- дальник убивает ближника сразу ---
        if (attackerCanKill && !defenderCanKill)
        {
            auto visitor = std::make_shared<FightVisitor>(attacker, textObserver);
            if (defender->accept(visitor))
            {
                std::lock_guard lock(state.npc_mutex);
                defender->kill();
            }
            fileObserver->onFight(attacker, defender, true);
            continue;
        }

        // --- взаимный бой только если оба могут атаковать ---
        if (attackerCanKill && defenderCanKill)
        {
            int attack = dice(gen);
            int defense = dice(gen);

            if (attack > defense)
            {
                auto visitor = std::make_shared<FightVisitor>(attacker, textObserver);
                if (defender->accept(visitor))
                {
                    std::lock_guard lock(state.npc_mutex);
                    defender->kill();
                    fileObserver->onFight(attacker, defender, true);
                }
                else
                {
                    fileObserver->onFight(attacker, defender, false);
                }
            }
        }

        std::this_thread::yield();
    }
}
