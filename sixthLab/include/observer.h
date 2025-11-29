#pragma once
#include <memory>
#include <string>

class NPC;

class IFightObserver
{
public:
    virtual ~IFightObserver() = default;
    virtual void onFight(const std::shared_ptr<NPC> &attacker, const std::shared_ptr<NPC> &defender, bool success) = 0;
};

class TextObserver : public IFightObserver
{
public:
    void onFight(const std::shared_ptr<NPC> &attacker,
                 const std::shared_ptr<NPC> &defender,
                 bool success) override;
};

class FileObserver : public IFightObserver
{
private:
    std::string filename;

public:
    FileObserver(const std::string &filename = "log.txt");
    void onFight(const std::shared_ptr<NPC> &attacker,
                 const std::shared_ptr<NPC> &defender,
                 bool success) override;
};