#include "Card.h"

using std::string

//Card constructor- update Cards fields according to the given parameters
Card::Card(const string name):
m_cardName(name)
{
    if(!cardNameIsValid(name))
    {
        
        throw DeckFileFormatError();
    }
}

~Card()
{
    delete[] this->m_cardName;
}

bool cardNameIsValid(const string name, const string cardTypes[], const int currentAmountOfCardTypes)
{
    for(int i = 0; i < currentAmountOfCardTypes, i++)
    {
        if(!name.compare(cardTypes[i]))
        {
            return true;
        }
    }
    return false;
}
