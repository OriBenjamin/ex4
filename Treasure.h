#ifndef TREASURE_H
#define TREASURE_H

#include "Card.h"

 
class Treasue : public Card
{
    
    public:
    
    Treasue();
    Treasue(const Treasue& treasue) = delete;
    ~Treasue() = default;
    Treasue& operator=(const Treasue& treasue) = delete;
    void cardEffect(const Player& player);

};



#endif //TREASURE_H