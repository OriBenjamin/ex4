#ifndef ROGUE_H
#define ROGUE_H
#include <iostream>

class Rogue : public Player
{
    public:
        Rogue() = delete;
        void addCoins(int coinsAmount);        
}
#endif //ROGUE_H