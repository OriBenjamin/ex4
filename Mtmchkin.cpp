#include "Mtmchkin.h"
#include <fstream>

using std::string;
using std::ifstream;
using std::cin;

Mtmchkin::Mtmchkin(const string fileName):
m_teamSize(0),
m_roundsCount(0)
{
    ifstream cardsFile(fileName, std::ifstream::in);
    if(!cardsFile.is_open())
    {
        throw DeckFileNotFound();
    }
    string cardName;
    int lineNumber = 0;
    bool gangIsValid = false;
    std::vector<string> namesOfCards;
    while(std::getline(cardsFile, cardName))
    {
        lineNumber++;
        if(cardName == "Gang")
        {
            while(std::getline(cardsFile, cardName))
            {
                lineNumber++;
                if(cardName == "Goblin" || cardName == "Vampire" || cardName == "Dragon")
                {
                    namesOfCards.push_back(cardName);
                }
                else if(cardName == "EndGang")
                {
                    gangIsValid = true;
                    break;
                }
                else
                {
                    throw DeckFileFormatError(lineNumber);
                }
            }
            if(!gangIsValid)
            {
                throw DeckFileFormatError(lineNumber + 1);
            }
            m_cards.push(new Gang(namesOfCards));
            continue;
        }
        if(cardName == "Goblin")
        {
            m_cards.push(new Goblin());
        }
        else if(cardName == "Dragon")
        {
            m_cards.push(new Dragon());
        }
        else if(cardName == "Fairy")
        {
            m_cards.push(new Fairy());
        }        
        else if(cardName == "Merchant")
        {
            m_cards.push(new Merchant());
        }   
        else if(cardName == "Pitfall")
        {
            m_cards.push(new Pitfall());
        }
        else if(cardName == "Treasure")
        {
            m_cards.push(new Treasure());
        }
        else if(cardName == "Vampire")
        {
            m_cards.push(new Vampire());
        }   
        else if(cardName == "Barfight")
        {
            m_cards.push(new Barfight());
        }
        else
        {
            throw DeckFileFormatError(lineNumber);
        }
    }
    cardsFile.close();
    if(lineNumber < 5)
    {
        throw DeckFileInvalidSize();
    }
    printStartGameMessage();
    printEnterTeamSizeMessage();
    do
    {
        cin >> m_teamSize;
        if(cin.fail() || m_teamSize < 2 || m_teamSize > 6)
        {
            printInvalidTeamSize();
            cin.clear();
            continue;
        }
        break;
    } while (true);
    string playerName;
    string playerKind;
    for(int i=0; i < m_teamSize; i++)
    {
        printInsertPlayerMessage();
        do
        {
            cin >> playerName;
            cin >> playerKind;
            if(!playerNameIsValid(playerName))
            {
                printInvalidName();
                continue;
            }
            if(playerKind == "Rogue")
            {
                m_players.push(new Rogue(playerName));
            }
            else if(playerKind == "Wizard")
            {
                m_players.push(new Wizard(playerName));
            }
            else if(playerKind == "Fighter")
            {
                m_players.push(new Fighter(playerName));
            }
            else
            {
                printInvalidClass();
                continue;
            }    
            break;
        } while(true);
    }
}
    

void Mtmchkin::playRound()
{
    m_roundsCount++;
    printRoundStartMessage(m_roundsCount);
    for(int i=0; i < m_teamSize; i++)
    {
        printTurnStartMessage(m_players.front()->getPlayerName());
        m_cards.front()->cardEffect(*(m_players.front()));
        if(m_players.front()->isKnockedOut())
        {
            m_losers.push_back(m_players.front());
            m_players.front() = NULL; //prevent destruction of player
            m_players.pop();
        }
        else if(m_players.front()->playerHasWon())
        {
            m_winners.push_back(m_players.front());
            m_players.front() = NULL;
            m_players.pop();
        }
        else
        {
            m_players.push(m_players.front());
            m_players.front() = NULL;
            m_players.pop();
        }
        m_cards.push(m_cards.front());
        m_cards.front() = NULL; //prevent destruction of card
        m_cards.pop();
    }
    m_teamSize = m_players.size();
    if(isGameOver())
    {
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int currentRank = 1;
    for(int i = 0; i < int(m_winners.size()); i++) ////forwards interation
    {
        printPlayerLeaderBoard(currentRank, *m_winners[i]);
        currentRank++;
    }
       
    std::queue<Player*> playersCopy = m_players;
    while (!playersCopy.empty())
    {
        printPlayerLeaderBoard(currentRank, *playersCopy.front());
        playersCopy.pop();
        currentRank++;
    }
 
    for(int i = m_losers.size()-1; i >= 0; i--) //backwards interation
    {
        printPlayerLeaderBoard(currentRank, *m_losers[i]);
        currentRank++;
    }
}
    

bool Mtmchkin::isGameOver() const
{
    return m_players.size() == 0;
}
    

int Mtmchkin::getNumberOfRounds() const
{
    return m_roundsCount;
}



