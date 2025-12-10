#pragma once
#include <vector>
#include <queue>
#include <memory>
#include <mutex>
#include <shared_mutex>

#include "npc.h"

struct FightTask
{
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class GameState
{
public:
    static constexpr int MAP_SIZE = 99;

    std::vector<std::shared_ptr<NPC>> npcs;
    std::queue<FightTask> fights;

    mutable std::shared_mutex npc_mutex;
    std::mutex fight_mutex;
    std::mutex cout_mutex;

    bool running = true;
};
