#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Hero.h"
#include "Warrior.h"
#include "Knight.h"
#include "Guild.h"
#include <iostream>

TEST_CASE("1: Hero Initialization and Getters", "[basic]")
{
    Hero h("Aragorn", 100, 50);
    REQUIRE(h.getName() == "Aragorn");
    REQUIRE(h.getHealth() == 100);
    REQUIRE(h.getPower() == 50);
}

TEST_CASE("2: Operator Overloading > and +", "[basic]")
{
    Hero h1("A", 100, 50);
    Hero h2("B", 80, 60);
    REQUIRE(h2 > h1);
    REQUIRE((h1 + h2) == 180);
}

TEST_CASE("3: Warrior Effective Health", "[inheritance]")
{
    Warrior w("Gimli", 100, 40, 10);
    REQUIRE(w.calculateEffectiveHealth() == 120); // 100 + (10*2)
}

TEST_CASE("4: Guild Composition += Logic", "[composition]")
{
    Guild g("Fellowship");
    Hero h1("Legolas", 80, 70);
    g += &h1;
    REQUIRE(g.calculateTotalGuildPower() == 70);
}
// Testing Const Correctness
TEST_CASE("5: Const Correctness Check", "[basic]")
{
    const Hero h("Arwen", 100, 50);
    // These functions MUST be marked 'const' in Hero.h or this test will fail to compile
    REQUIRE(h.getName() == "Arwen");
    REQUIRE(h.getHealth() == 100);
}

// 2. Testing Knight Functionality
TEST_CASE("6: Knight Burst Damage", "[inheritance]")
{
    Knight k("Arthur", 150, 60, 20, 25);
    // Power (60) + ChargeBonus (25) = 85
    REQUIRE(k.calculateBurstDamage() == 85);
}

// Testing Exact String Printing for Guild << Operator
TEST_CASE("7: Guild Display String Output", "[output]")
{
    Guild g("Rohan");
    Hero h1("Eomer", 100, 80);
    g += &h1;

    OutputCapture capture;
    std::cout << g;        // Uses the overloaded << operator
    std::string output = capture.getOutput();

    // Verification of exact string pattern
    // Note: Ensure your Guild.cpp output matches this spacing/format exactly
    REQUIRE(output.find("Guild: Rohan") != std::string::npos);
    REQUIRE(output.find("Members: 1") != std::string::npos);
    REQUIRE(output.find("- Eomer (Power: 80)") != std::string::npos);
}

// Testing Exact String Printing for Destructor
TEST_CASE("8: Guild Destructor Message", "[output]")
{
    std::string output;
    {
        OutputCapture capture;
        Guild *tempGuild = new Guild("Gondor");
        delete tempGuild; // This should trigger: "The guild Gondor has been disbanded!"
        output = capture.getOutput();
    }

    REQUIRE(output == "The guild Gondor has been disbanded!\n");
}
TEST_CASE("9: Guild Statistics Display", "[output]")
{
    Guild g("Valor");
    Hero h1("Aragorn", 100, 50);
    Hero h2("Legolas", 80, 60);
    g += &h1;
    g += &h2;

    OutputCapture capture;
    g.displayGuildStats();
    string output = capture.getOutput();

    // Verify the specific stats are present in the output
    REQUIRE(output.find("Guild Name: Valor") != string::npos);
    REQUIRE(output.find("Total Members: 2/15") != string::npos);
    REQUIRE(output.find("Total Guild Power: 110") != string::npos);
}
// Testing Guild Capacity Limit and Error Message
TEST_CASE("10: Guild Capacity Limit Error Message", "[guild][output]")
{
    Guild g("Overcrowded");
    Hero filler("Soldier", 50, 10);
    for (int i = 0; i < 15; i++)
    {
        g += &filler;
    }
    OutputCapture capture;
    Hero extra("Extra Hero", 100, 50);
    g += &extra;
    std::string output = capture.getOutput();

    // Verification of the exact error message
    REQUIRE(output == "Guild is at full capacity!\n");
}

int main()
{
    return runCatchTests();
}