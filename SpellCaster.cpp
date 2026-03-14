#include "SpellCaster.h"

SpellCaster::SpellCaster(int sp) {
    spellPower = sp;
}
int SpellCaster::getSpellPower() const {
    return spellPower;
}