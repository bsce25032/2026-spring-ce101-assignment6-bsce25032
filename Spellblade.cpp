#include "Spellblade.h"

Spellblade::Spellblade(std::string n, int h, int p, int sp) : Hero(n, h, p), MagicalEntity(sp) {
    
}
int Spellblade::calculateHybridDamage() const {
    return getPower() + getSpellPower();
}