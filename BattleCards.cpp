#include "BattleCards.h"

using std::string

BattleCard::BattleCard(const string name):
Card(name)
{}

ostream& operator<<(ostream& os, const BattleCard& battleCard)
{
    printCardDetails(os, battleCard.m_cardName);
    printMonsterDetails(os, battleCard.m_cardForce, battleCard.m_cardDamage, battleCard.m_cardLoot, false);
    printEndOfCardDetails(os);
    return os;
}

