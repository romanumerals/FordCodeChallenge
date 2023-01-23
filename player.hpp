#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <memory>
#include <random>
#include <vector>
#include <utility>

#include "cards.hpp"

class GameTable;

class Player
{
public:
	enum Action{HOLD, FOLD, CALL, RAISE};
private:
	int held_chips;
	int current_bet;
	std::unique_ptr<GameTable> game_table;
	Action lastAction;
	
	// This is the player's hand. It has to be split into two vectors
	// due to some variations like seven card stud where some player
	// cards are revealed to the other players.
	std::vector<Card> concealed_cards;
	std::vector<Card> revealed_cards;

public:
	Player();

	int getHeldChips();
	int getCurrentBet();
	std::vector<Card> getRevealedCards();
	std::vector<Card> getBestCurrentHand();
	Action getLastAction();

	void setGameTable(GameTable* table);
	void removeGameTable();

	void wonChips(int amount);

	// The second part of pair is for value of raise
	virtual std::pair<Action, int> MakeDecision()=0;
};

class HumanPlayer : Player
{
public:
	HumanPlayer();

	std::pair<Action, int> MakeDecision();
};

class AIPlayer : Player
{
public:
	AIPlayer();

	std::pair<Action, int> MakeDecision();
};

#endif