#include Mtmchkin.h
#include Player.h
#include Rogue.h
#include Exception.h
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
Mtmchkin::Mtmchkin(const std::string fileName):
m_teamSize(0),
m_roundCount(0),
{
    ofstream cardsFile(fileName); //catch wrong fileName
    if(!cardsFile)
    {
        throw DeckFileNotFound();
    }

    std::string cardName;
    int lineNumber = 1;
    while(std::getline(cardsFile,cardName))
    {
        switch(cardName)
        {
            case Goblin:
                m_cards.push(&Goblin(cardName));
                break;
            case Dragon:
                m_cards.push(&Dragon(cardName));
                break;
            case Fairy:
                m_cards.push(&Fairy(cardName));
                break;
            case Merchant:
                m_cards.push(&Merchant(cardName));
                break;
            case PitFall:
                m_cards.push(&PitFall(cardName));
                break;
            case Treasure:
                m_cards.push(&Treasure(cardName));
                break;
            case Vampire:
                m_cards.push(&Vampire(cardName));
                break;
            default:
                throw DeckFileFormatError(lineNumber);
        }
        lineNumber++;
    }
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
            printInvalidTeamSize()
            cin.clear();
            continue;
        }
        break;
    } while (true);
    string fullInput;
    string playerName;
    string playerKind;
    int firstSpaceIndex = 0;
    for(int i=0; i < teamSize; i++)
    {
        do
        {
            printInsertPlayerMessage();
            cin >> fullInput; //split into two parts
            if(fullInput.find(' ') == string::npos)
            {
                printInvalidName();
                continue;
            }
            playerName = fullInput.substr(0,fullInput.find(' '));
            playerKind = fullInput.substr(fullInput.find(' '),fullInput.length()-playerName.length());
            switch(playerKind)
                case Rogue:
                    m_players.push(&Rogue(playerName));
                    break;
                case Wizard:
                    m_cards.push(&Wizard(playerName));
                    break;
                case Fighter:
                    m_cards.push(&Fighter(playerName));
                    break;
                case Merchant:
                    m_cards.push(&Merchant(playerName));
                    break;
                default:
                    printInvalidClass();
                    continue; //continues loop
            break;
        } while(true);
    }
}
    

Mtmchkin::playRound()
{
    printRoundStartMessage(m_roundCount);
    for(int i=0; i < m_teamSize)
    {
        printTurnStartMessage(m_players.front()->getName());
        m_cards.front()->cardEffect(*(m_players.front());
        if(m_players.front()->isKnockedOut())
        {
            m_losers.push(m_players.front());
            m_players.front() = NULL; //prevent destruction of player
            m_players.pop();
            m_teamSize--;
        }
        else if(m_players.front()->hasWon())
        {
            m_winners.push(m_players.front());
            m_players.front() = NULL;
            m_players.pop();
            m_teamSize--;
        }
        else
        {
            m_players.push(m_players.front());
            m_cards.front() = NULL;
            m_players.pop();
        }
        m_cards.push(m_cards.front());
        m_cards.front() = NULL; //prevent destruction of card
        m_cards.pop();
    }
    m_roundCount++;
    if(isGameOver())
    {
        printGameEndMessage();
    }
}

Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int currentRank = 1;
    for(int i = 0; i < m_winners.size(); i++) ////forwards interation
    {
        printPlayerLeaderBoard(currentRank,m_winners[i]);
        currentRank++;
    }
    for(int i = m_losers.size() - 1; i >= 0; i--) //backwards interation
    {
        printPlayerLeaderBoard(currentRank,m_losers[i]);
        currentRank++;
    }
}
    

bool Mtmchkin::isGameOver() const
{
    return m_teamSize == 0;
}
    

int Mtmchkin::getNumberOfRounds() const
{
    return m_roundCount;
}



