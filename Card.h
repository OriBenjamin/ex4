#ifndef Card_H
#define Card_H

#include <string>
#include "utilities.h"
#include "Exception.h"

const int currentAmountOfCardTypes = Current_Amount_Of_Card_Types = 8;

class Card
{
    
    public:
    
    Card(const std::string name);
    Card(const Card& card) = delete;
    ~Card();
    Card& operator=(const Card& card) = delete;
    virtual void cardEffect() = 0;

    protected:
    std::string m_cardName;
};

const std::string cardTypes[8] = {"Goblin", "Vampire", "Dragon", "Merchant", "Treasure", "Pitfall", "Barfight", "Fairy"};
bool cardNameIsValid(const std::string name, const std::string cardTypes[] = cardTypes, const int currentAmountOfCardTypes = Current_Amount_Of_Card_Types);



#endif //Card_H
