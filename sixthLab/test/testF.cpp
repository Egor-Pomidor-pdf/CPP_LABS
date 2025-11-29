#include <gtest/gtest.h>
#include <memory>
#include <sstream>

#include "npc_factory.h"
#include "knight.h"
#include "squirrel.h"
#include "pegasus.h"
#include "observer.h"

// ---- Тесты фабрики ----
TEST(NPCFactoryTest, CreateByEnum)
{
    auto knight = NPCFactory::create(NpcType::Knight, "Arthur", 100, 100);
    auto squirrel = NPCFactory::create(NpcType::Squirrel, "Nutty", 50, 50);
    auto pegasus = NPCFactory::create(NpcType::Pegasus, "Wings", 200, 200);

    EXPECT_EQ(knight->getType(), "Knight");
    EXPECT_EQ(squirrel->getType(), "Squirrel");
    EXPECT_EQ(pegasus->getType(), "Pegasus");

    EXPECT_EQ(knight->getName(), "Arthur");
    EXPECT_EQ(squirrel->getName(), "Nutty");
    EXPECT_EQ(pegasus->getName(), "Wings");
}

// ---- Тест создания из потока ----
TEST(NPCFactoryTest, CreateFromStream)
{
    std::istringstream iss("Knight Lancelot 10 20\n");
    auto npc = NPCFactory::create(iss);
    EXPECT_EQ(npc->getType(), "Knight");
    EXPECT_EQ(npc->getName(), "Lancelot");
    EXPECT_EQ(npc->getX(), 10);
    EXPECT_EQ(npc->getY(), 20);
}

// ---- Тест боя: Knight убивает Squirrel ----
TEST(FightTest, KnightKillsSquirrel)
{
    auto knight = std::make_shared<Knight>("Arthur", 0, 0);
    auto squirrel = std::make_shared<Squirrel>("Nutty", 0, 0);

    auto observer = std::make_shared<TextObserver>();
    FightVisitor visitor(knight, observer);

    bool result = squirrel->accept(std::make_shared<FightVisitor>(knight, observer));
    EXPECT_TRUE(result);
}

// ---- Тест боя: Squirrel убивает Pegasus ----
TEST(FightTest, SquirrelKillsPegasus)
{
    auto squirrel = std::make_shared<Squirrel>("Nutty", 0, 0);
    auto pegasus = std::make_shared<Pegasus>("Wings", 0, 0);

    auto observer = std::make_shared<TextObserver>();
    FightVisitor visitor(squirrel, observer);

    bool result = pegasus->accept(std::make_shared<FightVisitor>(squirrel, observer));
    EXPECT_TRUE(result);
}

// ---- Тест боя: Pegasus никого не убивает ----
TEST(FightTest, PegasusKillsNobody)
{
    auto pegasus = std::make_shared<Pegasus>("Wings", 0, 0);
    auto knight = std::make_shared<Knight>("Arthur", 0, 0);
    auto squirrel = std::make_shared<Squirrel>("Nutty", 0, 0);

    auto observer = std::make_shared<TextObserver>();

    FightVisitor visitor1(pegasus, observer);
    EXPECT_FALSE(knight->accept(std::make_shared<FightVisitor>(pegasus, observer)));
    EXPECT_FALSE(squirrel->accept(std::make_shared<FightVisitor>(pegasus, observer)));
}
