#ifndef MAGICALENTITY_H
#define MAGICALENTITY_H

class MagicalEntity {
protected:
    int spellPower;

public:
    MagicalEntity(int sp);
    int getSpellPower() const;
};

#endif