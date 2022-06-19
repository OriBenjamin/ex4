#include "BattleCards.h"
#include <iostream>
using std::string;
using std::ostream;


BattleCard::BattleCard(const string name, const int cardLoot, const int cardForce, const int cardDamage):
Card(name),
m_cardLoot(cardLoot),
m_cardForce(cardForce),
m_cardDamage(cardDamage)
{}

ostream& operator<<(ostream& os, const BattleCard& battleCard)
{
    printCardDetails(os, battleCard.m_cardName);
    if(battleCard.m_cardName.compare("Dragon")==0)
    {
        printMonsterDetails(os, battleCard.m_cardForce, battleCard.m_cardDamage, battleCard.m_cardLoot, true);
    }
    else
    {
        printMonsterDetails(os, battleCard.m_cardForce, battleCard.m_cardDamage, battleCard.m_cardLoot, false);
    }
    printEndOfCardDetails(os);
    return os;
}

