#include <cmath>

#include "npc.h"

NPC::NPC(const std::string &name, int x, int y)
    : name(name), x(x), y(y), alive(true) {}

double NPC::distanceTo(const std::shared_ptr<NPC> &other) const
{
    double dx = double(x - other->getX());
    double dy = double(y - other->getY());
    return std::sqrt(dx * dx + dy * dy);
}