#ifndef PITFALL_H
#define PITFALL_H

#include "Card.h"

 
class Pitfall : public Card
{
    
    public:
    
    Pitfall();
    Pitfall(const Pitfall& pitfall) = delete;
    ~Pitfall() = default;
    Pitfall& operator=(const Pitfall& pitfall) = delete;
    void cardEffect(const Player& player);

};



#endif //PITFALL_H