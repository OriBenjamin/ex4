COMPILER = g++
PLAYERS_DIR = Players/
CARDS_DIR = Cards/
OBJS = Player.o utilities.o HealthPoints.o Fighter.o Rogue.o Wizard.o Card.o Barfight.o BattleCards.o Dragon.o Goblin.o Vampire.o Fairy.o Merchant.o Pitfall.o Treasure.o
EXEC = Test
DEBUG_FLAG = -g
COMP_FLAG = -std=c++11 -Wall -Werror

$(EXEC) : $(OBJS)
	$(COMPILER) $(DEBUG_FLAG) $(OBJS) -o $@

BattleCards.o: Exception.h utilities.h $(CARDS_DIR)Card.h $(PLAYERS_DIR)Player.h $(CARDS_DIR)BattleCards.h $(CARDS_DIR)BattleCards.cpp
	$(COMPILER) -c $(DEBUG_FLAG) $(COMP_FLAG) $(CARDS_DIR)BattleCards.cpp

Dragon.o: Exception.h utilities.h $(CARDS_DIR)Card.h $(PLAYERS_DIR)Player.h $(CARDS_DIR)BattleCards.h $(CARDS_DIR)Dragon.h $(CARDS_DIR)Dragon.cpp
	$(COMPILER) -c $(DEBUG_FLAG) $(COMP_FLAG) $(CARDS_DIR)Dragon.cpp

Vampire.o: Exception.h utilities.h $(CARDS_DIR)Card.h $(PLAYERS_DIR)Player.h $(CARDS_DIR)BattleCards.h $(CARDS_DIR)Vampire.h $(CARDS_DIR)Vampire.cpp
	$(COMPILER) -c $(DEBUG_FLAG) $(COMP_FLAG) $(CARDS_DIR)Vampire.cpp

Goblin.o: Exception.h utilities.h $(CARDS_DIR)Card.h $(PLAYERS_DIR)Player.h $(CARDS_DIR)BattleCards.h $(CARDS_DIR)Goblin.h $(CARDS_DIR)Goblin.cpp
	$(COMPILER) -c $(DEBUG_FLAG) $(COMP_FLAG) $(CARDS_DIR)Goblin.cpp

Barfight.o: Exception.h utilities.h $(CARDS_DIR)Card.h $(PLAYERS_DIR)Player.h $(CARDS_DIR)Barfight.h $(CARDS_DIR)Barfight.cpp
	$(COMPILER) -c $(DEBUG_FLAG) $(COMP_FLAG) $(CARDS_DIR)Barfight.cpp

Fairy.o: Exception.h utilities.h $(CARDS_DIR)Card.h $(PLAYERS_DIR)Player.h $(CARDS_DIR)Fairy.h $(CARDS_DIR)Fairy.cpp
	$(COMPILER) -c $(DEBUG_FLAG) $(COMP_FLAG) $(CARDS_DIR)Fairy.cpp

Merchant.o: Exception.h utilities.h $(CARDS_DIR)Card.h $(PLAYERS_DIR)Player.h $(CARDS_DIR)Merchant.h $(CARDS_DIR)Merchant.cpp
	$(COMPILER) -c $(DEBUG_FLAG) $(COMP_FLAG) $(CARDS_DIR)Merchant.cpp

Pitfall.o: Exception.h utilities.h $(CARDS_DIR)Card.h $(PLAYERS_DIR)Player.h $(CARDS_DIR)Pitfall.h $(CARDS_DIR)Pitfall.cpp
	$(COMPILER) -c $(DEBUG_FLAG) $(COMP_FLAG) $(CARDS_DIR)Pitfall.cpp

Treasure.o: Exception.h utilities.h $(CARDS_DIR)Card.h $(PLAYERS_DIR)Player.h $(CARDS_DIR)Treasure.h $(CARDS_DIR)Treasure.cpp
	$(COMPILER) -c $(DEBUG_FLAG) $(COMP_FLAG) $(CARDS_DIR)Treasure.cpp

Card.o: Exception.h utilities.h $(PLAYERS_DIR)Player.h $(CARDS_DIR)Card.h $(CARDS_DIR)Card.cpp
	$(COMPILER) -c $(DEBUG_FLAG) $(COMP_FLAG) $(CARDS_DIR)Card.cpp

Fighter.o: $(PLAYERS_DIR)HealthPoints.h Exception.h utilities.h $(PLAYERS_DIR)Player.h $(PLAYERS_DIR)Fighter.h $(PLAYERS_DIR)Fighter.cpp
	$(COMPILER) -c $(DEBUG_FLAG) $(COMP_FLAG) $(PLAYERS_DIR)Fighter.cpp

Rogue.o: $(PLAYERS_DIR)HealthPoints.h Exception.h utilities.h $(PLAYERS_DIR)Player.h $(PLAYERS_DIR)Rogue.h $(PLAYERS_DIR)Rogue.cpp
	$(COMPILER) -c $(DEBUG_FLAG) $(COMP_FLAG) $(PLAYERS_DIR)Rogue.cpp

Wizard.o: $(PLAYERS_DIR)HealthPoints.h Exception.h utilities.h $(PLAYERS_DIR)Player.h $(PLAYERS_DIR)Wizard.h $(PLAYERS_DIR)Wizard.cpp
	$(COMPILER) -c $(DEBUG_FLAG) $(COMP_FLAG) $(PLAYERS_DIR)Wizard.cpp

Player.o: $(PLAYERS_DIR)HealthPoints.h Exception.h utilities.h $(PLAYERS_DIR)Player.h $(CARDS_DIR)Card.h $(PLAYERS_DIR)Player.cpp
	$(COMPILER) -c $(DEBUG_FLAG) $(COMP_FLAG) $(PLAYERS_DIR)Player.cpp

utilities.o: Exception.h $(PLAYERS_DIR)Player.h utilities.h utilities.cpp
	$(COMPILER) -c $(DEBUG_FLAG) $(COMP_FLAG) utilities.cpp

HealthPoints.o: $(PLAYERS_DIR)HealthPoints.h $(PLAYERS_DIR)HealthPoints.cpp
	$(COMPILER) -c $(DEBUG_FLAG) $(COMP_FLAG) $(PLAYERS_DIR)HealthPoints.cpp

clean:
	rm -f $(OBJS) $(EXEC)
	