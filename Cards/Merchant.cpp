#include "Merchant.h"
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::getline;
using std::stoi;

const int BUY_NOTHING = 0;
const int BUY_ONE_HEALTHPOINT = 1;
const int BUY_ONE_FORCE_UNIT = 2;

const int ONE_HEALTHPOINT_PRICE = 5;
const int ONE_FORCE_UNIT_PRICE = 10;

Merchant::Merchant():
Card("Merchant")
{}

void Merchant::cardEffect(Player& player)
{
    printMerchantInitialMessageForInteractiveEncounter(cout, player.getPlayerName(), player.getPlayerCoins());
    string userInput;
    getline(cin, userInput);   
    while(stoi(userInput) != BUY_NOTHING && stoi(userInput) != BUY_ONE_HEALTHPOINT && stoi(userInput) != BUY_ONE_FORCE_UNIT)
    {
        printInvalidInput();
        getline(cin, userInput);
    }
    switch(stoi(userInput))
    {
        case BUY_NOTHING:
            printMerchantSummary(cout, player.getPlayerName(), BUY_NOTHING, 0);
            break;
        case BUY_ONE_HEALTHPOINT:
            if(player.getPlayerCoins() < ONE_HEALTHPOINT_PRICE)
            {
                printMerchantInsufficientCoins(cout);
                printMerchantSummary(cout, player.getPlayerName(), BUY_NOTHING, 0);
            }
            else
            {
                player.pay(ONE_HEALTHPOINT_PRICE);
                printMerchantSummary(cout, player.getPlayerName(), BUY_ONE_HEALTHPOINT, ONE_HEALTHPOINT_PRICE);
            }
            break;
        case BUY_ONE_FORCE_UNIT:
            if(player.getPlayerCoins() < ONE_FORCE_UNIT_PRICE)
            {
                printMerchantInsufficientCoins(cout);
                printMerchantSummary(cout, player.getPlayerName(), BUY_NOTHING, 0);
            }
            else
            {
                player.pay(ONE_FORCE_UNIT_PRICE);
                printMerchantSummary(cout, player.getPlayerName(), BUY_ONE_FORCE_UNIT, ONE_FORCE_UNIT_PRICE);
            }
            break;
    }
}
