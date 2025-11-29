#pragma once
#include <memory>

class NPC;
class Knight;
class Squirrel;
class Pegasus;
class IFightObserver;

class FightVisitor
{
private:
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<IFightObserver> observer;

public:
    FightVisitor(const std::shared_ptr<NPC> &attacker, const std::shared_ptr<IFightObserver> &observer = nullptr);

    bool visit(const std::shared_ptr<Knight> &defender);
    bool visit(const std::shared_ptr<Squirrel> &defender);
    bool visit(const std::shared_ptr<Pegasus> &defender);

    std::shared_ptr<NPC> getAttacker() const { return attacker; }
};