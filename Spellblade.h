#ifndef SPELLBLADE_H
#define SPELLBLADE_H
#include "Hero.h"
#include "MagicalEntity.h"
#include <string>

class Spellblade : public Hero, public MagicalEntity {
public:
    Spellblade(std::string n, int h, int p, int sp);
    int calculateHybridDamage() const;
};

#endif