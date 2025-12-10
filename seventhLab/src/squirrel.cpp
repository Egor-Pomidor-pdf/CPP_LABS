#include "squirrel.h"
#include "knight.h"
#include "pegasus.h"

Squirrel::Squirrel(const std::string &name, int x, int y) : NPC(name, x, y) {}

bool Squirrel::accept(const std::shared_ptr<FightVisitor> &attacker)
{
    return attacker->visit(std::static_pointer_cast<Squirrel>(shared_from_this()));
}

bool Squirrel::fight(const std::shared_ptr<Knight> &other)
{
    return false;
}

bool Squirrel::fight(const std::shared_ptr<Squirrel> &other)
{
    return getName() < other->getName();
}

bool Squirrel::fight(const std::shared_ptr<Pegasus> &other)
{
    return true;
}