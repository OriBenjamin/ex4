#include "Goblin.h"

using std::string;

Goblin::Goblin():
BattleCard("Goblin"),
m_cardLoot(2),
m_cardForce(6),
m_cardDamage(10)
{}
   
void Goblin::cardEffect(const Player& player)
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
        try
        {
            player.damage(this->m_cardDamage);
        }
        catch(InvalidArgument& exception)
        {
            throw InvalidArgument();
        }
        catch(PlayerHasAlreadyDied& exception)
        {
            throw PlayerHasAlreadyDied();
        }
        printLossBattle(player.m_playerName, this->m_cardName);

    }
}