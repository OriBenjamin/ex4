#ifndef BattleCards_H
#define BattleCards_H

#include <string>
#include "Card.h"
#include "utilities.h"


class BattleCard : public Card
{
    
    public:
    
    BattleCard(const std::string name);
    BattleCard(const BattleCard& battleCard) = delete;
    virtual ~BattleCard() = default;
    BattleCard& operator=(const BattleCard& battleCard) = delete;
    virtual friend std::ostream& operator<<(std::ostream& os, const BattleCard& battleCard);
    virtual void cardEffect() = 0;

    protected:

    std::string m_cardName;
    const int m_cardLoot;
    const int m_cardForce;
    const int m_cardDamage;
};

#endif //BattleCards_H
