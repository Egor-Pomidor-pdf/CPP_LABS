#include <iostream>
#include <fstream>

#include "observer.h"
#include "npc.h"

void TextObserver::onFight(const std::shared_ptr<NPC> &attacker, const std::shared_ptr<NPC> &defender, bool success)
{
    if (success)
    {
        std::cout << attacker->getType() << " '" << attacker->getName() << "' killed "
                  << defender->getType() << " '" << defender->getName() << "'\n";
    }
    else
    {
        std::cout << attacker->getType() << " '" << attacker->getName() << "' failed to kill "
                  << defender->getType() << " '" << defender->getName() << "'\n";
    }
}

FileObserver::FileObserver(const std::string &filename) : filename(filename) {}

void FileObserver::onFight(const std::shared_ptr<NPC> &attacker, const std::shared_ptr<NPC> &defender, bool success)
{
    std::ofstream ofs(filename, std::ios::app);
    if (!ofs)
        return;
    if (success)
    {
        ofs << attacker->getType() << " '" << attacker->getName() << "' killed "
            << defender->getType() << " '" << defender->getName() << "'\n";
    }
    else
    {
        ofs << attacker->getType() << " '" << attacker->getName() << "' failed to kill "
            << defender->getType() << " '" << defender->getName() << "'\n";
    }
}