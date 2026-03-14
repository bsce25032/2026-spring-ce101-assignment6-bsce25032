#ifndef GUILD_H
#define GUILD_H
#include "Hero.h"
#include <iostream>
using namespace std;

class Guild {
private:
    string guildName;
    Hero* roster[15];
    int memberCount;

public:
    Guild(string name);
    void operator+=(Hero* newHero);
    int calculateTotalGuildPower() const;
    void displayGuildStats() const;
    friend ostream& operator<<(ostream& os, const Guild& g);
    ~Guild();
};

#endif