#include "Pitfall.h"

using std::string;

const int DAMAGE_FROM_FALLING_INTO_A_PIT = 10;
Pitfall::Pitfall():
Card("Pitfall")
{}

void Pitfall::cardEffect(const Player& player)
{
    if(player.m_playerJob != "Rogue")
    {
        try
        {
            player.damage(DAMAGE_FROM_FALLING_INTO_A_PIT);
            printPitfallMessage(false);
        }
        catch(PlayerHasAlreadyDied& exception)
        {
            throw PlayerHasAlreadyDied();
        }
    }
    else
    {
        printPitfallMessage(true);

    }
}