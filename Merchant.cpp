#include "Merchant.h"
#include <iostream>

using std::string;
using std::cin;
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

void Merchant::cardEffect(const Player& player)
{
    string userInput;
    while(stoi(userInput) !=BUY_NOTHING || stoi(userInput) !=BUY_ONE_HEALTHPOINT || stoi(userInput) !=BUY_ONE_FORCE_UNIT)
    {
        printInvalidInput();
        cin.getline(userInput);
    }
    switch(stoi(userInput))
    {
        case BUY_NOTHING:
            printMerchantSummary(player.m_playerName, BUY_NOTHING, 0);
        case BUY_ONE_HEALTHPOINT:
            if(player.m_playerCoins < ONE_HEALTHPOINT_PRICE)
            {
                printMerchantInsufficientCoins();
                printMerchantSummary(player.m_playerName, BUY_NOTHING, 0);
            }
            else
            {
                player.m_playerCoins -= ONE_HEALTHPOINT_PRICE;
                printMerchantSummary(player.m_playerName, BUY_ONE_HEALTHPOINT, ONE_HEALTHPOINT_PRICE);
            }
        case BUY_ONE_FORCE_UNIT:
            if(player.m_playerCoins < ONE_FORCE_UNIT_PRICE)
            {
                printMerchantInsufficientCoins();
                printMerchantSummary(player.m_playerName, BUY_NOTHING, 0);
            }
            else
            {
                player.m_playerCoins -= ONE_FORCE_UNIT_PRICE;
                printMerchantSummary(player.m_playerName, BUY_ONE_FORCE_UNIT, ONE_FORCE_UNIT_PRICE);
            }
    }
}

/*void Merchant::cardEffect(const Player& player)
{
    string userInput;
    printMerchantInitialMessageForInteractiveEncounter(player.m_playerName, player.m_playerCoins);
    Merchant::tryToBuy(cin.getline(userInput));
}

void Merchant::invalidInput(string& userInput)
{
    while(stoi(userInput) !=BUY_NOTHING || stoi(userInput) !=BUY_ONE_HEALTHPOINT || stoi(userInput) !=BUY_ONE_FORCE_UNIT)
    {
        printInvalidInput();
        cin.getline(userInput);
    }
}

void Merchant::tryToBuy(string& userInput)
{
    Merchant::invalidInput(); //checking if the user input is invalid
    if(stoi(userInput) == BUY_NOTHING)
    {
        printMerchantSummary(player.m_playerName, BUY_NOTHING, 0);
    }
    if(stoi(userInput) == BUY_ONE_HEALTHPOINT)
    {
        if(player.m_playerCoins < ONE_HEALTHPOINT_PRICE)
        {
            printMerchantInsufficientCoins();
            Merchant::notEnughMoneyToBuy(cin.getline(userInput));
        }
        else
        {
            player.m_playerCoins -= ONE_HEALTHPOINT_PRICE;
            printMerchantSummary(player.m_playerName, BUY_ONE_HEALTHPOINT, ONE_HEALTHPOINT_PRICE);
        }
    }
    if(stoi(userInput) == BUY_ONE_FORCE_UNIT)
    {
        if(player.m_playerCoins < ONE_FORCE_UNIT_PRICE)
        {
            printMerchantInsufficientCoins();
            Merchant::notEnughMoneyToBuy(cin.getline(userInput));
        }
        else
        {
            player.m_playerCoins -= ONE_FORCE_UNIT_PRICE;
            printMerchantSummary(player.m_playerName, BUY_ONE_FORCE_UNIT, ONE_FORCE_UNIT_PRICE);
        }
    }
}*/