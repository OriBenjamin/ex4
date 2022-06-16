#include "Player.h"
#include "Rouge.h"
#include <iostream>

void Rogue::addCoins(int coinsAmount)
{
    if(coinsAmount>0)
    {
        this->m_coins += 2*coinsAmount; 
    }  
}