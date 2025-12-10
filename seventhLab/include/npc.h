#pragma once
#include <memory>
#include <string>

class FightVisitor;

class NPC
{
protected:
    std::string name;
    int x, y;
    bool alive;

public:
    NPC(const std::string &name, int x, int y);
    virtual ~NPC() = default;

    virtual bool accept(const std::shared_ptr<FightVisitor> &attacker) = 0;

    virtual bool fight(const std::shared_ptr<class Knight> &other) = 0;
    virtual bool fight(const std::shared_ptr<class Squirrel> &other) = 0;
    virtual bool fight(const std::shared_ptr<class Pegasus> &other) = 0;

    std::string getName() const { return name; }
    int getX() const { return x; }
    int getY() const { return y; }
    bool isAlive() const { return alive; }
    void kill() { alive = false; }
    void setPosition(int nx, int ny) {
        x = nx;
        y = ny;
    }

    double distanceTo(const std::shared_ptr<NPC> &other) const;

    virtual std::string getType() const = 0;
};

using NPCPtr = std::shared_ptr<NPC>;