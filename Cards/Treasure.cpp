#include "Treasure.h"

using std::string;

const int TREASURE_OF_COINS = 10;
Treasue::Treasue():
Card("Treasue")
{}

void Treasue::cardEffect(Player& player)
{
    player.addCoins(TREASURE_OF_COINS);
    printTreasureMessage();
}