#include "pegasus.h"
#include "knight.h"
#include "squirrel.h"

Pegasus::Pegasus(const std::string &name, int x, int y) : NPC(name, x, y) {}

bool Pegasus::accept(const std::shared_ptr<FightVisitor> &attacker)
{
    return attacker->visit(std::static_pointer_cast<Pegasus>(shared_from_this()));
}

bool Pegasus::fight(const std::shared_ptr<Knight> &other)
{
    return false;
}

bool Pegasus::fight(const std::shared_ptr<Squirrel> &other)
{
    return false;
}

bool Pegasus::fight(const std::shared_ptr<Pegasus> &other)
{
    return getName() < other->getName();
}