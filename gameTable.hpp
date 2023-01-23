#ifndef GAME_TABLE_HPP
#define GAME_TABLE_HPP

#include <iostream>
#include <random>
#include <vector>
#include <utility>

#include "cards.hpp"
#include "player.hpp"

class GameTable
{
private:
	Deck deck;
	std::vector<Player> player_list;
	std::vector<Card> community_cards;

public:
	GameTable();

	void addPlayer(Player new_player);
	void removePlayer(Player player);
	void beginGame();

	void dealFiveCard();
	void dealSevenCard();
	void dealTexasHoldem();
	
	void playFiveCard();
	void playSevenCard();
	void playTexasHoldem();

	Player determineWinningPlayer();
	
	int scoreHand(std::vector<Card>);
	std::vector<std::pair<Player, std::vector<Card>>> getPlayerVisibleCards();
	std::vector<Card> getCommunityCards();
};

#endif