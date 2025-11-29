#include "knight.h"
#include "squirrel.h"
#include "pegasus.h"

Knight::Knight(const std::string &name, int x, int y) : NPC(name, x, y) {}

bool Knight::accept(const std::shared_ptr<FightVisitor> &attacker)
{
    return attacker->visit(std::static_pointer_cast<Knight>(shared_from_this()));
}

bool Knight::fight(const std::shared_ptr<Knight> &other)
{
    return getName() < other->getName();
}

bool Knight::fight(const std::shared_ptr<Squirrel> &other)
{
    return true;
}

bool Knight::fight(const std::shared_ptr<Pegasus> &other)
{
    return true;
}