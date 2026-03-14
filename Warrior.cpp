#include "Warrior.h"

Warrior::Warrior(string n, int h, int p, int armor) : Hero(n, h, p) {
    armorRating = armor;
}
int Warrior::calculateEffectiveHealth() const {
    return getHealth() + (armorRating * 2);
}