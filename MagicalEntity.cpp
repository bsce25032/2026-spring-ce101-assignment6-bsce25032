#include "MagicalEntity.h"

MagicalEntity::MagicalEntity(int sp) {
    spellPower = sp;
}
int MagicalEntity::getSpellPower() const {
    return spellPower;
}