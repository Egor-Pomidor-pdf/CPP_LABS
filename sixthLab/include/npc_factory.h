#pragma once
#include <memory>
#include <iostream>

#include "npc.h"

enum class NpcType
{
    Knight,
    Squirrel,
    Pegasus
};

class NPCFactory
{
public:
    static std::shared_ptr<NPC> create(NpcType type, const std::string &name, int x, int y);
    static std::shared_ptr<NPC> create(std::istream &is);
    static void save(const std::shared_ptr<NPC> &npc, std::ostream &os);
};