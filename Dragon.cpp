#include "Dragon.h"

using std::string;
using std::ostream;

const int INFINITY = 0; //the value of infinity does not important but its meaning
Dragon::Dragon():
BattleCard("Dragon"),
m_cardLoot(1000),
m_cardForce(25),
m_cardDamage(INFINITY)
{}


ostream& operator<<(ostream& os, const BattleCard& battleCard)
{
    printCardDetails(os, battleCard.m_cardName);
    printMonsterDetails(os, battleCard.m_cardForce, battleCard.m_cardDamage, battleCard.m_cardLoot, true);
    printEndOfCardDetails(os);
    return os;
}


void Dragon::cardEffect(const Player& player)
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
        printWinBattle(player.m_playerName, this->m_cardName);
    }
    else
    {
       (player.m_playerHp).m_currentHealthPoints = 0;
        printLossBattle(player.m_playerName, this->m_cardName);
    }
}