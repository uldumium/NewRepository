#pragma once
//Установка курсора по заданным координатам
void setCursor(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hConsole, coord);
}
//Печать имени карты
void printName(int a) {
	if (a == (int)CardName::ACE) {
		std::cout << " A\t";
	}
	else if (a == (int)CardName::JACK) {
		std::cout << " B\t";
	}
	else if (a == (int)CardName::QUEEN) {
		std::cout << " Q\t";
	}
	else if (a == (int)CardName::KING) {
		std::cout << " K\t";
	}
	else if (a == 10) {
		std::cout << a << "\t";
	}
	else {
		std::cout<<" " << a << "\t";
	}
}
//Печать масти карты
void printSuit(int a) {
	if (a == (int)Suit::BUBA) {
		std::cout << "\033[1;31m" << (char)4 << "\033[1;0m";
	}
	else if (a == (int)Suit::CHERVA) {
		std::cout << "\033[1;31m" << (char)3 << "\033[1;0m";
	}
	else if (a == (int)Suit::PIKA) {
		std::cout << (char)6;
	}
	else if (a == (int)Suit::TREFA) {
		std::cout << (char)5;
	}
}
//Перетасовка колоды карт
void Shuffle(Card* deck) {
	srand(time(NULL));
	Card buffer;
	for (int i = 0; i < 52; i++)
	{
		int r = i + (rand() % (52 - i));
		buffer.name = deck[i].name;
		buffer.suit = deck[i].suit;

		deck[i].name = deck[r].name;
		deck[i].suit = deck[r].suit;

		deck[r].name = buffer.name;
		deck[r].suit = buffer.suit;
	}
	for (int i = 0; i < 52; i++)
	{
		int r = i + (rand() % (52 - i));
		buffer.name = deck[i].name;
		buffer.suit = deck[i].suit;

		deck[i].name = deck[r].name;
		deck[i].suit = deck[r].suit;

		deck[r].name = buffer.name;
		deck[r].suit = buffer.suit;
	}
}
//Печать в консоль колоды карт
void showAll(Card* deck) {
	for (int i = (int)Suit::TREFA; i <= (int)Suit::BUBA; i++)
	{
		for (int j = (int)CardName::ACE; j <= (int)CardName::KING; j++)
		{
			int index = (13 * i) + j - 1;
			printSuit((int)deck[index].suit);
			printName((int)deck[index].name);
		}
		std::cout << std::endl;
	}
}
//Заполнение колоды карт
void Setup(Card* deck) {
	for (int i = (int)Suit::TREFA; i <= (int)Suit::BUBA; i++)
	{
		for (int j = (int)CardName::ACE; j <= (int)CardName::KING; j++)
		{
			int index = (13 * i) + j - 1;
			Card c;
			c.name = (CardName)j;
			c.suit = (Suit)i;
			deck[index] = c;
		}
	}
}
//Структура описывающая массивы игрового поля
struct SetupBoard {

	Card* one = new Card[7];
	Card* two = new Card[7];
	Card* three = new Card[7];
	Card* four = new Card[7];
	Card* five = new Card[6];
	Card* six = new Card[6];
	Card* seven = new Card[6];
	Card* eight = new Card[6];
	//Метод заполнения массивов
	void GoToBoard(Card* deck) {
		for (int i = 0, k = 0, q = 0, w = 0, e = 0, r = 0, t = 0, y = 0; i < 52; i++)
		{
			if (i < 7) {
				one[i].name = deck[i].name;
				one[i].suit = deck[i].suit;
			}
			else if (i < 14) {
				two[k].name = deck[i].name;
				two[k].suit = deck[i].suit;
				k++;
			}
			else if (i < 21) {
				three[q].name = deck[i].name;
				three[q].suit = deck[i].suit;
				q++;
			}
			else if (i < 28) {
				four[w].name = deck[i].name;
				four[w].suit = deck[i].suit;
				w++;
			}
			else if (i < 34) {
				five[e].name = deck[i].name;
				five[e].suit = deck[i].suit;
				e++;
			}
			else if (i < 40) {
				six[r].name = deck[i].name;
				six[r].suit = deck[i].suit;
				r++;
			}
			else if (i < 46) {
				seven[t].name = deck[i].name;
				seven[t].suit = deck[i].suit;
				t++;
			}
			else if (i < 52) {
				eight[y].name = deck[i].name;
				eight[y].suit = deck[i].suit;
				y++;
			}
		}
	}

	//печать по определенным позициям на поле
	void printPosition(Card* stack,int x = 0, int y = 0) {
		if (stack == one) {
			x = 10;
			y = 10;
		}
		else if (stack == two) {
			x = 15;
			y = 10;
		}
		else if (stack == three) {
			x = 20;
			y = 10;
		}
		else if (stack == four) {
			x = 25;
			y = 10;
		}
		else if (stack == five) {
			x = 30;
			y = 10;
		}
		else if (stack == six) {
			x = 35;
			y = 10;
		}
		else if (stack == seven) {
			x = 40;
			y = 10;
		}
		else if (stack == eight) {
			x = 45;
			y = 10;
		}
		
		for (int i = 0; i < (_msize(stack)/sizeof(stack)/2); i++)
		{
			setCursor(x, y++);
			printSuit((int)stack[i].suit);
			printName((int)stack[i].name);
		}
		setCursor(x, y++);
		std::cout << "   ";
		setCursor(2, 21);
	}
	//метод перемещения карт
	void moving(Card* &first, Card* &last) {
			int size = (_msize(first) / sizeof(first) / 2);
			int size1 = (_msize(last) / sizeof(last) / 2);

			if (size == 0) {
				setCursor(2, 20);
				std::cout << "Position one - no card";
			}
			else if((int)first[size-1].name == (int)last[size1-1].name - 1 && (int)first[size-1].suit != (int)last[size1-1].suit && (int)first[size - 1].suit != (int)Suit::CHERVA){

			//else if ((int)first[ size - 1].name == (int)last[size1 - 1].name - 1 && (int)first[size - 1].suit != (int)last[size1 - 1].suit) {
				Card* buffer = new Card[size - 1];
				Card* buffer1 = new Card[size1 + 1];

				for (int i = 0; i < size - 1; i++)
				{
					buffer[i].name = first[i].name;
					buffer[i].suit = first[i].suit;

				}

				for (int i = 0; i < size1; i++)
				{
					buffer1[i].name = last[i].name;
					buffer1[i].suit = last[i].suit;
				}
				buffer1[(_msize(buffer1) / sizeof(buffer1) / 2) - 1].name = first[size - 1].name;
				buffer1[(_msize(buffer1) / sizeof(buffer1) / 2) - 1].suit = first[size - 1].suit;

				delete[]first;
				delete[]last;

				first = buffer;
				last = buffer1;

				printPosition(first);
				printPosition(last);
			}
			else if ((int)first[size - 1].name == (int)last[size1 - 1].name - 1 && (int)first[size - 1].suit != (int)last[size1 - 1].suit && (int)first[size - 1].suit != (int)Suit::BUBA) {

				//else if ((int)first[ size - 1].name == (int)last[size1 - 1].name - 1 && (int)first[size - 1].suit != (int)last[size1 - 1].suit) {
				Card* buffer = new Card[size - 1];
				Card* buffer1 = new Card[size1 + 1];

				for (int i = 0; i < size - 1; i++)
				{
					buffer[i].name = first[i].name;
					buffer[i].suit = first[i].suit;

				}

				for (int i = 0; i < size1; i++)
				{
					buffer1[i].name = last[i].name;
					buffer1[i].suit = last[i].suit;
				}
				buffer1[(_msize(buffer1) / sizeof(buffer1) / 2) - 1].name = first[size - 1].name;
				buffer1[(_msize(buffer1) / sizeof(buffer1) / 2) - 1].suit = first[size - 1].suit;

				delete[]first;
				delete[]last;

				first = buffer;
				last = buffer1;

				printPosition(first);
				printPosition(last);
			}
			else if ((int)first[size - 1].name == (int)last[size1 - 1].name - 1 && (int)first[size - 1].suit != (int)last[size1 - 1].suit && (int)first[size - 1].suit != (int)Suit::PIKA) {

				//else if ((int)first[ size - 1].name == (int)last[size1 - 1].name - 1 && (int)first[size - 1].suit != (int)last[size1 - 1].suit) {
				Card* buffer = new Card[size - 1];
				Card* buffer1 = new Card[size1 + 1];

				for (int i = 0; i < size - 1; i++)
				{
					buffer[i].name = first[i].name;
					buffer[i].suit = first[i].suit;

				}

				for (int i = 0; i < size1; i++)
				{
					buffer1[i].name = last[i].name;
					buffer1[i].suit = last[i].suit;
				}
				buffer1[(_msize(buffer1) / sizeof(buffer1) / 2) - 1].name = first[size - 1].name;
				buffer1[(_msize(buffer1) / sizeof(buffer1) / 2) - 1].suit = first[size - 1].suit;

				delete[]first;
				delete[]last;

				first = buffer;
				last = buffer1;

				printPosition(first);
				printPosition(last);
			}
			else if ((int)first[size - 1].name == (int)last[size1 - 1].name - 1 && (int)first[size - 1].suit != (int)last[size1 - 1].suit && (int)first[size - 1].suit != (int)Suit::TREFA) {

				//else if ((int)first[ size - 1].name == (int)last[size1 - 1].name - 1 && (int)first[size - 1].suit != (int)last[size1 - 1].suit) {
				Card* buffer = new Card[size - 1];
				Card* buffer1 = new Card[size1 + 1];

				for (int i = 0; i < size - 1; i++)
				{
					buffer[i].name = first[i].name;
					buffer[i].suit = first[i].suit;

				}

				for (int i = 0; i < size1; i++) 
				{
					buffer1[i].name = last[i].name;
					buffer1[i].suit = last[i].suit;
				}
				buffer1[(_msize(buffer1) / sizeof(buffer1) / 2) - 1].name = first[size - 1].name;
				buffer1[(_msize(buffer1) / sizeof(buffer1) / 2) - 1].suit = first[size - 1].suit;

				delete[]first;
				delete[]last;

				first = buffer;
				last = buffer1;

				printPosition(first);
				printPosition(last);
			}
	}
	//Массивы буффера для одной карты
	Card* one1 = new Card[0];
	Card* two1 = new Card[0];
	Card* three1 = new Card[0];
	Card* four1 = new Card[0];

	void PrintBuffer(Card* stack, int x = 0, int y = 0) {
		if (stack == one1) {
			x = 8;
			y = 5;
		}
		else if (stack == two1) {
			x = 13;
			y = 5;
		}
		else if (stack == three1) {
			x = 18;
			y = 5;
		}
		else if (stack == four1) {
			x = 23;
			y = 5;
		}
		int size = _msize(stack) / sizeof(Card);
		if (size == 0) {
			setCursor(x, y++);
			std::cout << "    ";
		}
		else {
			for (int i = 0; i < _msize(stack) / sizeof(Card); i++)
			{
				setCursor(x, y++);
				printSuit((int)stack[i].suit);
				printName((int)stack[i].name);
			}
		}
		
	}
	//метод перемещения карты в массив из буфферов
	void BoardToBuffer(Card*& first, Card*& last) {
		int sizeFirst = _msize(first) / sizeof(Card);
		int sizeLast = _msize(last) / sizeof(Card);
		if (sizeFirst == 0) {
			setCursor(2, 20);
			std::cout << "Position one - no card";
		}
		else if (sizeLast == 1) {
			setCursor(2, 20);
			std::cout << "Maximum one card!";
		}
		else {
			Card* bufferFirst = new Card[sizeFirst - 1];
			Card* bufferLast = new Card[sizeLast + 1];

			for (int i = 0; i < sizeFirst - 1; i++)
			{
				bufferFirst[i].name = first[i].name;
				bufferFirst[i].suit = first[i].suit;
			}
			for (int i = 0; i < sizeLast; i++)
			{
				bufferLast[i].name = last[i].name;
				bufferLast[i].suit = last[i].suit;
			}

			bufferLast[sizeLast].name = first[sizeFirst - 1].name;
			bufferLast[sizeLast].suit = first[sizeFirst - 1].suit;

			delete[] first;
			delete[] last;

			first = bufferFirst;
			last = bufferLast;

			printPosition(first);
			PrintBuffer(last);

		}

	}
	//перемещение карты из буффера на поле
	void BufferToBoard(Card*& first, Card*& last) {
		int sizeFirst = _msize(first) / sizeof(Card);
		int sizeLast = _msize(last) / sizeof(Card);
		if (sizeFirst == 0) {
			setCursor(2, 20);
			std::cout << "                       ";
			setCursor(2, 20);
			std::cout << "Position one - no card";
		}
		else if (sizeLast == 1) {
			setCursor(2, 20);
			std::cout << "                       ";
			setCursor(2, 20);
			std::cout << "Maximum one card!";
		}
		else {
			Card* bufferFirst = new Card[sizeFirst - 1];
			Card* bufferLast = new Card[sizeLast + 1];

			for (int i = 0; i < sizeFirst - 1; i++)
			{
				bufferFirst[i].name = first[i].name;
				bufferFirst[i].suit = first[i].suit;
			}
			for (int i = 0; i < sizeLast; i++)
			{
				bufferLast[i].name = last[i].name;
				bufferLast[i].suit = last[i].suit;
			}

			bufferLast[sizeLast].name = first[sizeFirst - 1].name;
			bufferLast[sizeLast].suit = first[sizeFirst - 1].suit;

			delete[] first;
			delete[] last;

			first = bufferFirst;
			last = bufferLast;

			printPosition(last);
			PrintBuffer(first);

		}

	}

	Card* endOne = new Card[0];
	Card* endTwo = new Card[0];
	Card* endThree = new Card[0];
	Card* endFour = new Card[0];


};
