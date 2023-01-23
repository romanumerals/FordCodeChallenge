#ifndef CARDS_HPP
#define CARDS_HPP

#include <algorithm>
#include <random>
#include <vector>

struct Card
{
	enum Suit{Spades, Clubs, Hearts, Diamonds};
	enum Value{Ace, King, Queen, Jack, Ten, Nine, Eight, Seven, Six, Five, Four, Three, Two};

	Suit suit;
	Value value;

	bool operator==(const Card& rhs);
	bool operator>(const Card& rhs);
	bool operator<(const Card& rhs);
};

class Deck
{
private:
	std::vector<Card> card_deck;
public:
	Deck();

	void resetDeck();
	void shuffleDeck();
	std::vector<Card> dealCards(int num_to_deal);
};

#endif