#ifndef DRAGON_H
#define DRAGON_H

#include "BattleCards.h"


class Dragon : public BattleCard
{
    
    public:
    
    Dragon();
    Dragon(const Dragon& dragon) = delete;
    ~Dragon() = default;
    Dragon& operator=(const Dragon& dragon) = delete;
    friend std::ostream& operator<<(std::ostream& os, const Card& card) override;
    void cardEffect(const Player& player);

    
};

#endif //DRAGON_H