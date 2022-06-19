#include "Barfight.h"

using std::string;

const int DAMAGE_AT_BAR_FIGHT = 10;

Barfight::Barfight():
Card("Barfight")
{}

void Barfight::cardEffect(Player& player)
{
    if(player.getPlayerJob() != "Fighter")
    {
        try
        {
            player.damage(DAMAGE_AT_BAR_FIGHT);
            printBarfightMessage(false);
        }
        catch(PlayerHasAlreadyDied& exception)
        {
            throw PlayerHasAlreadyDied();
        }
    }
    else
    {
        printBarfightMessage(true);
    }
}