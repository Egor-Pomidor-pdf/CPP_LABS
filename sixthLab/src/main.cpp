#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>

#include "npc.h"
#include "npc_factory.h"
#include "fight_visitor.h"
#include "observer.h"
#include "knight.h"
#include "squirrel.h"
#include "pegasus.h"

int main()
{
    std::vector<std::shared_ptr<NPC>> npcs;

    auto textObserver = std::make_shared<TextObserver>();
    auto fileObserver = std::make_shared<FileObserver>("log.txt");

    std::cout << "Balagur Fate 3 — Dungeon Editor\n";

    while (true)
    {
        std::cout << "Commands: add, list, save, load, fight, quit\n> ";
        std::string cmd;
        if (!(std::cin >> cmd))
            break;

        if (cmd == "add")
        {
            std::string type, name;
            int x, y;
            std::cin >> type >> name >> x >> y;
            if (x < 0 || x > 500 || y < 0 || y > 500)
            {
                std::cout << "Coordinates must be 0..500\n";
                continue;
            }
            std::istringstream iss(type + " " + name + " " + std::to_string(x) + " " + std::to_string(y));
            auto npc = NPCFactory::create(iss);
            if (!npc)
            {
                std::cout << "Unknown type\n";
            }
            else
            {
                npcs.push_back(npc);
            }
        }
        else if (cmd == "list")
        {
            for (auto &n : npcs)
            {
                if (!n->isAlive())
                    continue;
                std::cout << n->getType() << " " << n->getName()
                          << " (" << n->getX() << "," << n->getY() << ")\n";
            }
        }
        else if (cmd == "save")
        {
            std::string filename;
            std::cin >> filename;
            std::ofstream ofs(filename);
            for (auto &n : npcs)
                if (n->isAlive())
                    NPCFactory::save(n, ofs);
            std::cout << "Saved\n";
        }
        else if (cmd == "load")
        {
            std::string filename;
            std::cin >> filename;
            std::ifstream ifs(filename);
            if (!ifs)
            {
                std::cout << "Can't open file\n";
                continue;
            }
            npcs.clear();
            while (ifs)
            {
                auto npc = NPCFactory::create(ifs);
                if (npc)
                    npcs.push_back(npc);
            }
            std::cout << "Loaded\n";
        }
        else if (cmd == "fight")
        {
            double range;
            std::cin >> range;
            for (size_t i = 0; i < npcs.size(); ++i)
            {
                if (!npcs[i]->isAlive())
                    continue;
                for (size_t j = i + 1; j < npcs.size(); ++j)
                {
                    if (!npcs[j]->isAlive())
                        continue;
                    if (npcs[i]->distanceTo(npcs[j]) <= range)
                    {
                        auto visitor1 = std::make_shared<FightVisitor>(npcs[i], textObserver);
                        bool iWins = npcs[j]->accept(visitor1);
                        if (iWins)
                        {
                            npcs[j]->kill();
                            fileObserver->onFight(npcs[i], npcs[j], true);
                        }
                        else
                        {
                            fileObserver->onFight(npcs[i], npcs[j], false);
                        }

                        if (npcs[j]->isAlive())
                        {
                            auto visitor2 = std::make_shared<FightVisitor>(npcs[j], textObserver);
                            bool jWins = npcs[i]->accept(visitor2);
                            if (jWins)
                            {
                                npcs[i]->kill();
                                fileObserver->onFight(npcs[j], npcs[i], true);
                            }
                            else
                            {
                                fileObserver->onFight(npcs[j], npcs[i], false);
                            }
                        }
                    }
                }
            }
        }
        else if (cmd == "quit")
            break;
        else
            std::cout << "Unknown command\n";
    }

    return 0;
}
