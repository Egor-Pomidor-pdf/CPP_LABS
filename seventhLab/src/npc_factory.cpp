#include <sstream>

#include "npc_factory.h"
#include "knight.h"
#include "squirrel.h"
#include "pegasus.h"

std::shared_ptr<NPC> NPCFactory::create(NpcType type, const std::string &name, int x, int y)
{
    switch (type)
    {
    case NpcType::Knight:
        return std::make_shared<Knight>(name, x, y);
    case NpcType::Squirrel:
        return std::make_shared<Squirrel>(name, x, y);
    case NpcType::Pegasus:
        return std::make_shared<Pegasus>(name, x, y);
    }
    return nullptr;
}

std::shared_ptr<NPC> NPCFactory::create(std::istream &is)
{
    std::string type;
    if (!(is >> type))
        return nullptr;
    std::string name;
    int x, y;
    if (!(is >> name >> x >> y))
        return nullptr;

    if (type == "Knight")
        return create(NpcType::Knight, name, x, y);
    if (type == "Squirrel")
        return create(NpcType::Squirrel, name, x, y);
    if (type == "Pegasus")
        return create(NpcType::Pegasus, name, x, y);
    return nullptr;
}

void NPCFactory::save(const std::shared_ptr<NPC> &npc, std::ostream &os)
{
    os << npc->getType() << " " << npc->getName() << " " << npc->getX() << " " << npc->getY() << "\n";
}