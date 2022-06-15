#include "Player.h"
#include "utilities.h"
#include <iostream>

using std::string;

const int DEFAULT_LEVEL = 1;
const int DEFAULT_COINS = 10;
const int DEFAULT_MAX_HP = 100;
const int DEFAULT_FORCE = 5;
const int DEFAULT_MAX_HEALTH = 100;



/*Player constructor- update Players fields according to the given parameters
or defaults values*/
Player::Player(const string name, const string job):
m_playerName(name),
m_playerJob(job),
m_playerHp(DEFAULT_MAX_HEALTH),
m_playerLevel(DEFAULT_LEVEL),
m_playerCoins(DEFAULT_COINS),
m_playerForce(DEFAULT_FORCE)
{
    if(!playerNameIsValid(playerName))
    {
        throw InvalidPlayerName();
    }
    if(playerClassIsValid(job))
    {
        throw InvalidPlayerClass();
    }
}

Player::~Player()
{
    delete[] this->m_playerName;
    delete[] this->m_playerJob;
}


//increasing player level
void Player::levelUp()
{
    if(this->m_playerLevel < 10)
    {
        this->m_playerLevel++;
    }
    else
    {
        throw PlayerHasAlreadyWon();
    }
}


//increasing players force
void Player::buff(const int buffAmount)
{
    this->m_playerForce += buffAmount;
    if(this->m_playerForce < 0)
    {
        this->m_playerForce = 0;
    }
}


//increasing players heal points
void Player::heal(const int healAmount) 
{
    if(healAmount <= 0)
    {
        throw InvalidArgument();
        
    }
    else
    {
        this->m_playerHp += healAmount;
    }
}

//decreasing players heal points
void Player::damage(const int damageAmount)
{
    if(damageAmount <= 0)
    {
        throw InvalidArgument();
    }
    else
    {
        try
        {
            this->m_playerHp -= damageAmount;
        }
        catch(PlayerHasAlreadyDied& exception)
        {
            throw PlayerHasAlreadyDied();
        }
    }
}


//checks if the player died
bool Player::isKnockedOut()
{
    return this->m_playerHp == 0;
}


//increasing players coins
void Player::addCoins(const int coinsAmount) 
{
    if(coinsAmount <= 0)
    {
        throw InvalidArgument();
    }
    else
    {
        this->m_playerCoins += coinsAmount; 
    }
}


//decreasing players coins depending the payment he made
void Player::pay(const int payAmount)
{
    if(payAmount <= 0 )
    {
        throw InvalidArgument();
    }
    if(this->m_playerCoins < payAmount)
    {
        throw PlayerHasNotEnughCoins();
    }  
    else
    {
        this->m_playerCoins -= payAmount;
    }
}

//checks players attack strength
int Player::getAttackStrength()
{
    return this->m_playerForce + this->m_playerLevel;
}


bool playerNameIsValid(const string name);
{
    int nameLength = 0;
    while(name != nullptr)
    {
        nameLength++;
        //check the character's validity according to thier assci values
        if(nameLength > 15 || int(*name) < 65  || (int(*name) > 90 && int(*name) < 97) || int(*name) > 122 || int(*name) == 32)
        {
            return false;
        }
        name++;
    }
    return true;
}

bool playerClassIsValid(const string name, const string playerJobTypes[], const int currentAmountOfPlayerTypes)
{
    for(int i = 0; i < Current_Amount_Of_Player_Types, i++)
    {
        if(!name.compare(playerJobTypes[i]))
        {
            return true;
        }
    }
    return false;
}

