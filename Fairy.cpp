#include "Fairy.h"

using std::string;

const int HEAL_FROM_A_FAIRY = 10;
Fairy::Fairy():
Card("Fairy")
{}

void Fairy::cardEffect(const Player& player)
{
    if(player.m_playerJob == "Wizard")
    {
        try
        {
            player.heal(HEAL_FROM_A_FAIRY);
            printFairyMessage(true);
        }
        catch(PlayerHasAlreadyWon& exception)
        {
            throw PlayerHasAlreadyWon();
        }
    }
    else
    {
        printFairyMessage(false);
    }
}