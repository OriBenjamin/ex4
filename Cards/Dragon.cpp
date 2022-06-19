#include "Dragon.h"

using std::string;
using std::ostream;

const int INFINITY = 0; //the value of infinity does not important except for its meaning
Dragon::Dragon():
BattleCard("Dragon", 1000, 25, INFINITY)
{}

/*
ostream& operator<<(ostream& os, const BattleCard& battleCard)
{
    printCardDetails(os, battleCard.m_cardName);
    printMonsterDetails(os, battleCard.m_cardForce, battleCard.m_cardDamage, battleCard.m_cardLoot, true);
    printEndOfCardDetails(os);
    return os;
}
*/

void Dragon::cardEffect(Player& player)
{
    if(player.getAttackStrength() >= this->m_cardForce)
    {
        try
        {
            player.levelUp();
            player.addCoins(this->m_cardLoot);
        }
        catch(PlayerHasAlreadyWon& exception)
        {
            throw PlayerHasAlreadyWon();
        }
        printWinBattle(player.getPlayerName(), this->m_cardName);
    }
    else
    {
       (player.getPlayerHp()).setCurrentHealthPoints(0);
        printLossBattle(player.getPlayerName(), this->m_cardName);
    }
}