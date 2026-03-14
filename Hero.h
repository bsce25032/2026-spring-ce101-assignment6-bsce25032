#ifndef HERO_H
#define HERO_H
#include <iostream>
#include <string>
using namespace std;

class Hero {
private:
    string name;
    int health;
    int basePower;

public:
    Hero(string n, int h, int p);
    string getName() const;
    int getHealth() const;
    int getPower() const;
    void takeDamage(int damage);
    bool operator>(const Hero &other) const;
    int operator+(const Hero &other) const;
};

#endif