#ifndef SPELLCASTER_H
#define SPELLCASTER_H

class SpellCaster {
protected:
    int spellPower;

public:
    SpellCaster(int sp);
    int getSpellPower() const;
};

#endif