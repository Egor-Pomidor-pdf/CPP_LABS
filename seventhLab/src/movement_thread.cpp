#include <random>
#include <thread>
#include <chrono>
#include <cmath>

#include "movement_thread.h"


static int clamp(int v, int min, int max)
{
    return std::max(min, std::min(v, max));
}

void movement_thread(GameState &state)
{
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> move(-5, 5);

    while (state.running)
    {
        {
            std::unique_lock lock(state.npc_mutex);

            for (auto &a : state.npcs)
            {
                if (!a->isAlive())
                    continue;

                int nx = clamp(a->getX() + move(gen), 0, GameState::MAP_SIZE);
                int ny = clamp(a->getY() + move(gen), 0, GameState::MAP_SIZE);
                a->setPosition(nx, ny);

                for (auto &b : state.npcs)
                {
                    if (a == b || !b->isAlive())
                        continue;

                    double dx = a->getX() - b->getX();
                    double dy = a->getY() - b->getY();

                    if (std::sqrt(dx * dx + dy * dy) <= 10)
                    {
                        std::lock_guard qlock(state.fight_mutex);
                        state.fights.push({a, b});
                    }
                }
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}
