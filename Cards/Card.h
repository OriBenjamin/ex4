#ifndef Card_H
#define Card_H

#include <string>
#include "../Exception.h"
#include "../Players/Player.h"
#include "../utilities.h"
const int CURRENT_AMOUNT_OF_CARD_TYPES = 8;

class Card
{
    
    public:
    
    Card(const std::string name);
    Card(const Card& card) = delete;
    ~Card() = default;
    Card& operator=(const Card& card) = delete;
    virtual void cardEffect() = 0;

    protected:
    std::string m_cardName;
};

const std::string cardTypes[8] = {"Goblin", "Vampire", "Dragon", "Merchant", "Treasure", "Pitfall", "Barfight", "Fairy"};
bool cardNameIsValid(const std::string name, const std::string cardTypes[] = cardTypes, const int currentAmountOfCardTypes = CURRENT_AMOUNT_OF_CARD_TYPES);



#endif //Card_H
