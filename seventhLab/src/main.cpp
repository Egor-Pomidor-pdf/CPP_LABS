#include <iostream>
#include <thread>
#include <chrono>
#include <random>

#include "game_state.h"
#include "movement_thread.h"
#include "fight_thread.h"
#include "npc_factory.h"

int main()
{
    GameState state;

    // --- генерация NPC ---
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> pos(0, GameState::MAP_SIZE);
    std::uniform_int_distribution<int> type(0, 2);

    for (int i = 0; i < 50; ++i)
    {
        NpcType t = static_cast<NpcType>(type(gen));
        std::string name = "npc_" + std::to_string(i);

        auto npc = NPCFactory::create(t, name, pos(gen), pos(gen));
        state.npcs.push_back(npc);
    }

    // --- запуск потоков ---
    std::thread moveThread(movement_thread, std::ref(state));
    std::thread fightThread(fight_thread, std::ref(state));

    // --- основной поток: вывод карты ---
    auto start = std::chrono::steady_clock::now();

    while (true)
    {
        auto now = std::chrono::steady_clock::now();
        int seconds = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();
        if (seconds >= 30)
            break;

        {
            std::shared_lock lock(state.npc_mutex);
            std::lock_guard cout_lock(state.cout_mutex);

            std::cout << "\n=== MAP STATE (" << seconds << "s) ===\n";
            for (auto &npc : state.npcs)
            {
                if (npc->isAlive())
                {
                    std::cout << npc->getType()
                              << " " << npc->getName()
                              << " (" << npc->getX()
                              << ", " << npc->getY() << ")\n";
                }
            }
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // --- остановка игры ---
    state.running = false;

    moveThread.join();
    fightThread.join();

    // --- вывод выживших ---
    std::cout << "\n=== SURVIVORS ===\n";
    for (auto &npc : state.npcs)
    {
        if (npc->isAlive())
        {
            std::cout << npc->getType()
                      << " " << npc->getName() << "\n";
        }
    }

    return 0;
}
