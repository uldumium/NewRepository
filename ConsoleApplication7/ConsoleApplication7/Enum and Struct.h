#pragma once
enum class CardName {
	ACE = 1,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING
};

enum class Suit {
	TREFA,
	PIKA,
	CHERVA,
	BUBA
};

struct Card
{
	CardName name;
	Suit suit;
};