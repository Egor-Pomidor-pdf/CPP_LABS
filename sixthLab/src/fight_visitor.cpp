#include "fight_visitor.h"
#include "npc.h"
#include "knight.h"
#include "squirrel.h"
#include "pegasus.h"
#include "observer.h"

FightVisitor::FightVisitor(const std::shared_ptr<NPC> &attacker, const std::shared_ptr<IFightObserver> &observer)
    : attacker(attacker), observer(observer) {}

bool FightVisitor::visit(const std::shared_ptr<Knight> &defender)
{
    if (auto aKnight = std::dynamic_pointer_cast<Knight>(attacker))
    {
        bool res = aKnight->fight(defender);
        if (observer)
            observer->onFight(attacker, defender, res);
        return res;
    }
    if (auto aSquirrel = std::dynamic_pointer_cast<Squirrel>(attacker))
    {
        bool res = aSquirrel->fight(defender);
        if (observer)
            observer->onFight(attacker, defender, res);
        return res;
    }
    if (auto aPegasus = std::dynamic_pointer_cast<Pegasus>(attacker))
    {
        bool res = aPegasus->fight(defender);
        if (observer)
            observer->onFight(attacker, defender, res);
        return res;
    }
    return false;
}

bool FightVisitor::visit(const std::shared_ptr<Squirrel> &defender)
{
    if (auto aKnight = std::dynamic_pointer_cast<Knight>(attacker))
    {
        bool res = aKnight->fight(defender);
        if (observer)
            observer->onFight(attacker, defender, res);
        return res;
    }
    if (auto aSquirrel = std::dynamic_pointer_cast<Squirrel>(attacker))
    {
        bool res = aSquirrel->fight(defender);
        if (observer)
            observer->onFight(attacker, defender, res);
        return res;
    }
    if (auto aPegasus = std::dynamic_pointer_cast<Pegasus>(attacker))
    {
        bool res = aPegasus->fight(defender);
        if (observer)
            observer->onFight(attacker, defender, res);
        return res;
    }
    return false;
}

bool FightVisitor::visit(const std::shared_ptr<Pegasus> &defender)
{
    if (auto aKnight = std::dynamic_pointer_cast<Knight>(attacker))
    {
        bool res = aKnight->fight(defender);
        if (observer)
            observer->onFight(attacker, defender, res);
        return res;
    }
    if (auto aSquirrel = std::dynamic_pointer_cast<Squirrel>(attacker))
    {
        bool res = aSquirrel->fight(defender);
        if (observer)
            observer->onFight(attacker, defender, res);
        return res;
    }
    if (auto aPegasus = std::dynamic_pointer_cast<Pegasus>(attacker))
    {
        bool res = aPegasus->fight(defender);
        if (observer)
            observer->onFight(attacker, defender, res);
        return res;
    }
    return false;
}