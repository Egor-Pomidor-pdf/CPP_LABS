#include "fight_thread.h"
#include "fight_visitor.h"
#include "observer.h"
#include <random>
#include <thread>

void fight_thread(GameState &state)
{
    auto observer = std::make_shared<TextObserver>();
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dice(1, 6);

    while (state.running)
    {
        FightTask task;

        {
            std::lock_guard lock(state.fight_mutex);
            if (state.fights.empty())
            {
                continue;
            }
            task = state.fights.front();
            state.fights.pop();
        }

        if (!task.attacker->isAlive() || !task.defender->isAlive())
            continue;

        int attack = dice(gen);
        int defense = dice(gen);

        if (attack > defense)
        {
            auto visitor = std::make_shared<FightVisitor>(task.attacker, observer);
            bool success = task.defender->accept(visitor);

            if (success)
            {
                std::lock_guard lock(state.npc_mutex);
                task.defender->kill();
            }
        }

        std::this_thread::yield();
    }
}
