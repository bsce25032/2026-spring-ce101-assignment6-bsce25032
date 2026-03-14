#include <iostream>
#include "Guild.h"
#include "Warrior.h"
#include "Knight.h"
#include "Spellblade.h"

using namespace std;

int main() {

    Guild g("Dragon Slayers");
    Warrior* w1 = new Warrior("Thor", 120, 50, 20);
    Knight* k1 = new Knight("Arthur", 140, 60, 25, 40);
    Spellblade* s1 = new Spellblade("Ezio", 100, 45, 35);
    g += w1;
    g += k1;
    g += s1;
    cout << g << endl;
    cout << "Warrior Effective Health: " << w1->calculateEffectiveHealth() << endl;
    cout << "Knight Burst Damage: " << k1->calculateBurstDamage() << endl;
    cout << "Spellblade Hybrid Damage: " << s1->calculateHybridDamage() << endl;

    return 0;
}