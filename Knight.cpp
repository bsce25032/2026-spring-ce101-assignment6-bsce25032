#include "Knight.h"

Knight::Knight(string n, int h, int p, int armor, int charge) : Warrior(n, h, p, armor) {
    chargeBonus = charge;
}
int Knight::calculateBurstDamage() const {
    return getPower() + chargeBonus;
}