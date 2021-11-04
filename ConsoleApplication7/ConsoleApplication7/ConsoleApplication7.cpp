#include "Header.h"
#include "Enum and Struct.h"
#include "Function.h"


int main()
{
	int x = 0, y = 0;
	Card cards[52];
	Setup(cards);
	_getch();
	system("cls");
	Shuffle(cards);
	std::cout << std::endl;
	//showAll(cards);
	std::cout << std::endl;
	SetupBoard deck;
	deck.GoToBoard(cards);
	x = 11;
	y = 9;
	for (int i = 1; i <= 8; i++)
	{
		setCursor(x, y);
		std::cout << "\033[1;44m" << i << "\033[1;0m";
		x += 5;
	}
	deck.printPosition(deck.one,10,10);
	deck.printPosition(deck.two, 15, 10);
	deck.printPosition(deck.three, 20, 10);
	deck.printPosition(deck.four, 25, 10);
	deck.printPosition(deck.five, 30, 10);
	deck.printPosition(deck.six, 35, 10);
	deck.printPosition(deck.seven, 40, 10);
	deck.printPosition(deck.eight, 45, 10);
	while (true)
	{
		int a = _getch() - 48;
		switch (a)
		{
		case 1: {
			int b = _getch() - 48;
			switch (b)
			{
			case 2: {
				deck.moving(deck.one, deck.two);
				break;
			}
			case 3: {
				deck.moving(deck.one, deck.three);
				break;
			}
			case 4: {
				deck.moving(deck.one, deck.four);
				break;
			}
			case 5: {
				deck.moving(deck.one, deck.five);
				break;
			}
			case 6: {
				deck.moving(deck.one, deck.six);
				break;
			}
			case 7: {
				deck.moving(deck.one, deck.seven);
				break;
			}
			case 8: {
				deck.moving(deck.one, deck.eight);
				break;
			}
			
			default:
				break;
			}
			break;
		}
		case 2: {
			int b = _getch() - 48;
			switch (b)
			{
			case 1: {
				deck.moving(deck.two, deck.one);
				break;
			}
			case 3: {
				deck.moving(deck.two, deck.three);
				break;
			}
			case 4: {
				deck.moving(deck.two, deck.four);
				break;
			}
			case 5: {
				deck.moving(deck.two, deck.five);
				break;
			}
			case 6: {
				deck.moving(deck.two, deck.six);
				break;
			}
			case 7: {
				deck.moving(deck.two, deck.seven);
				break;
			}
			case 8: {
				deck.moving(deck.two, deck.eight);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 3: {
			int b = _getch() - 48;
			switch (b)
			{
			case 2: {
				deck.moving(deck.three, deck.two);
				break;
			}
			case 1: {
				deck.moving(deck.three, deck.one);
				break;
			}
			case 4: {
				deck.moving(deck.three, deck.four);
				break;
			}
			case 5: {
				deck.moving(deck.three, deck.five);
				break;
			}
			case 6: {
				deck.moving(deck.three, deck.six);
				break;
			}
			case 7: {
				deck.moving(deck.three, deck.seven);
				break;
			}
			case 8: {
				deck.moving(deck.three, deck.eight);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 4: {
			int b = _getch() - 48;
			switch (b)
			{
			case 2: {
				deck.moving(deck.four, deck.two);
				break;
			}
			case 3: {
				deck.moving(deck.four, deck.three);
				break;
			}
			case 1: {
				deck.moving(deck.four, deck.one);
				break;
			}
			case 5: {
				deck.moving(deck.four, deck.five);
				break;
			}
			case 6: {
				deck.moving(deck.four, deck.six);
				break;
			}
			case 7: {
				deck.moving(deck.four, deck.seven);
				break;
			}
			case 8: {
				deck.moving(deck.four, deck.eight);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 5: {
			int b = _getch() - 48;
			switch (b)
			{
			case 2: {
				deck.moving(deck.five, deck.two);
				break;
			}
			case 3: {
				deck.moving(deck.five, deck.three);
				break;
			}
			case 4: {
				deck.moving(deck.five, deck.four);
				break;
			}
			case 1: {
				deck.moving(deck.five, deck.one);
				break;
			}
			case 6: {
				deck.moving(deck.five, deck.six);
				break;
			}
			case 7: {
				deck.moving(deck.five, deck.seven);
				break;
			}
			case 8: {
				deck.moving(deck.five, deck.eight);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 6: {
			int b = _getch() - 48;
			switch (b)
			{
			case 2: {
				deck.moving(deck.six, deck.two);
				break;
			}
			case 3: {
				deck.moving(deck.six, deck.three);
				break;
			}
			case 4: {
				deck.moving(deck.six, deck.four);
				break;
			}
			case 5: {
				deck.moving(deck.six, deck.five);
				break;
			}
			case 1: {
				deck.moving(deck.six, deck.one);
				break;
			}
			case 7: {
				deck.moving(deck.six, deck.seven);
				break;
			}
			case 8: {
				deck.moving(deck.six, deck.eight);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 7: {
			int b = _getch() - 48;
			switch (b)
			{
			case 2: {
				deck.moving(deck.seven, deck.two);
				break;
			}
			case 3: {
				deck.moving(deck.seven, deck.three);
				break;
			}
			case 4: {
				deck.moving(deck.seven, deck.four);
				break;
			}
			case 5: {
				deck.moving(deck.seven, deck.five);
				break;
			}
			case 6: {
				deck.moving(deck.seven, deck.six);
				break;
			}
			case 1: {
				deck.moving(deck.seven, deck.one);
				break;
			}
			case 8: {
				deck.moving(deck.seven, deck.eight);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 8: {
			int b = _getch() - 48;
			switch (b)
			{
			case 2: {
				deck.moving(deck.eight, deck.two);
				break;
			}
			case 3: {
				deck.moving(deck.eight, deck.three);
				break;
			}
			case 4: {
				deck.moving(deck.eight, deck.four);
				break;
			}
			case 5: {
				deck.moving(deck.eight, deck.five);
				break;
			}
			case 6: {
				deck.moving(deck.eight, deck.six);
				break;
			}
			case 7: {
				deck.moving(deck.eight, deck.seven);
				break;
			}
			case 1: {
				deck.moving(deck.eight, deck.one);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 9: {
			int b = _getch() - 48;
			switch (b)
			{
			case 1: {
				deck.BoardToBuffer(deck.one, deck.one1);
				break;
			}
			case 2: {
				deck.BoardToBuffer(deck.one, deck.two1);
				break;
			}
			case 3: {
				deck.BoardToBuffer(deck.one, deck.three1);
				break;
			}
			case 4: {
				deck.BoardToBuffer(deck.one, deck.four1);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 0: {
			int b = _getch() - 48;
			switch (b)
			{
			case 1: {
				deck.BufferToBoard(deck.one1, deck.one);
				break;
			}
			case 2: {
				deck.BufferToBoard(deck.two1, deck.one);
				break;
			}
			case 3: {
				deck.BufferToBoard(deck.three1, deck.one);
				break;
			}
			case 4: {
				deck.BufferToBoard(deck.four1, deck.one);
				break;
			}
			default:
				break;
			}
			break;
		}
		default:
			break;
		}
	}
	std::cout << "\n\n\n\n";
}
