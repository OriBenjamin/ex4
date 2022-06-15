#ifndef BARFIGHT_H
#define BARFIGHT_H

#include "Card.h"

 
class Barfight : public Card
{
    
    public:
    
    Barfight();
    Barfight(const Pitfall& barfight) = delete;
    ~Barfight() = default;
    Barfight& operator=(const Barfight& barfight) = delete;
    void cardEffect(const Player& player);

};



#endif //BARFIGHT_H