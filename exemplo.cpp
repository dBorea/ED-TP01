#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cctype>
#include <cmath>

const short NUMBER_OF_CARDS = 5;

using namespace std;

//convert string array containing card values (2-10, Q, J, K, A) into numerical values (2-14)
void convert_array(string value_str[], short value[]);

//convert single string element (2-10, Q, J, K, A) into numerical value (2-14)
short convert_value(string value);

//returns true if the cards are all of the same suit
//returns false otherwise
bool same_suit(string suit[]);

//returns true if the cards consist of a straight combination
//returns false otherwise
bool straight(short value[]);

//input is an array of card values
//function outputs array sepcifying how many times same value cards occured along with
//the size of the array (i.e. the number of times cards of different values were encountered)
void occurences(short value[], short num_of_combos[], short& size);

//tests for multiple occurences of cards
//"four" becomes true if there's four of a kind in set of cards -- "four" is false otherwise
//"three" becomes true if there's three of a kind in set of cards -- "three" is false otherwise
//"pair" becomes true if there's two of a kind in set of cards -- "pair" is false otherwise
//"two_pair" becomes true if there are two pairs in a set of cards -- "two_pair" is false otherwise
void check_cards( bool& four, bool& three, bool& pair, bool& two_pair, short num_of_combos[], short& size);

int main()
{
	char choice = 'n';
	do
	{
		string card[NUMBER_OF_CARDS];
		short value[NUMBER_OF_CARDS];
		string value_str[NUMBER_OF_CARDS];
		string suit[NUMBER_OF_CARDS];
		for(short i = 0; i < NUMBER_OF_CARDS; i++)
		{
			cout << "Enter a card in suit/value format: ";
			getline(cin, card[i]);
			suit[i] = card[i].substr(0, 1);
			value_str[i] = card[i].substr(1, card[i].length() - 1);
		}
		convert_array(value_str, value);
		
		short num_of_combos[NUMBER_OF_CARDS], size(0);
		occurences(value, num_of_combos, size);

		bool pair(false), two_pair(false), three(false), four(false);

		//TESTING
		check_cards(four, three, pair, two_pair, num_of_combos, size);
		bool is_straight = straight(value);
		bool is_same_suit = same_suit(suit);
		if(is_same_suit && is_straight)
		{
			cout << "Straight Flush\n\n";
		}
		else if(is_straight)
		{
			cout << "Straight\n\n";
		}
		else if(four)
		{
			cout << "Four of a kind\n\n";
		}
		else if(three && pair)
		{
			cout << "Full House\n\n";
		}
		else if(is_same_suit)
		{
			cout << "Flush\n\n";
		}
		else if(two_pair)
		{
			cout << "Two pairs\n\n";
		}
		else if(pair)
		{
			cout << "Pair\n\n";
		}
		else//nothing
		{
			cout << "Nothing\n\n";
		}

		cout << "Do you wish to run this program again? (y/n): ";
		cin >> choice;
		choice = tolower(choice);
		while((choice != 'y') && (choice != 'n'))
		{
			cout << "Incorrect input. Do you wish to run this program again? (y/n): ";
			cin >> choice;
		}

	}while(choice == 'y');

	cout << "End of the program.\nEnter key to continue\n\n";
	system("pause");

    return 0;
}

void convert_array(string value_str[], short value[])
{
	for(short i = 0; i < NUMBER_OF_CARDS; i++)
	{
		value[i] = convert_value(value_str[i]);
	}
	return;
}

short convert_value(string value)
{
	if(value == "2")
	{
		return 2;
	}
	else if(value == "3")
	{
		return 3;
	}
	else if(value == "4")
	{
		return 4;
	}
	else if(value == "5")
	{
		return 5;
	}
	else if(value == "6")
	{
		return 6;
	}
	else if(value == "7")
	{
		return 7;
	}
	else if(value == "8")
	{
		return 8;
	}
	else if(value == "9")
	{
		return 9;
	}
	else if(value == "10")
	{
		return 10;
	}
	else if((value == "q") || (value == "Q"))
	{
		return 11;
	}
	else if((value == "j") || (value == "J"))
	{
		return 12;
	}
	else if((value == "k") || (value == "K"))
	{
		return 13;
	}
	else//((value == "a") || (value == "A"))
	{
		return 14;
	}
}

bool same_suit(string suit[])
{
	string test = suit[0];
	for(short i = 1; i < NUMBER_OF_CARDS; i++)
	{
		if(test != suit[i])
		{
			return false;
		}
	}
	return true;
}

bool straight(short value[])
{
	short min = value[0];
	for(short i = 1; i < NUMBER_OF_CARDS; i++)
	{
		if(value[i] < min)
		{
			min = value[i];
		}
	}

	short next = min + 1;
	short i = 0;
	while(i < NUMBER_OF_CARDS)
	{
		if(value[i] == next)
		{
			next++;
			i=0;
		}
		else
		{
			i++;
		}
	}

	//The while loop above will set "next" equal to 5 more than "min" if there is a straight
	if(next == (min+5))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void occurences(short value[], short num_of_combos[], short& size)
{
	short k = 0;
	short count;
	bool encountered[] = {false, false, false, false, false};
	for(short i = 0; i < NUMBER_OF_CARDS; i++)
	{
		if(!encountered[i])
		{
			size++;
			encountered[i] = true;
			count = 1;
			for(short j = 1;  j < NUMBER_OF_CARDS; j++)
			{
				if((!encountered[j]) && (value[i] == value[j]))
				{
					encountered[j] = true;
					count++;
				}
			}
			num_of_combos[k] = count;
			k++;
		}
	}
	return;
}

void check_cards(bool& four, bool& three, bool& pair, bool& two_pair, short num_of_combos[], short& size)
{
	short pairs(0), threes(0), fours(0);
	for(short i = 0; i < size; i++)
	{
		if(num_of_combos[i] == 2)
		{
			pairs++;
		}
		if(num_of_combos[i] == 3)
		{
			three = true;
		}
		if(num_of_combos[i] == 4)
		{
			four = true;
		}
	}

	if(pairs == 2)
	{
		two_pair = true;
	}
	else if(pairs == 1)
	{
		pair = true;
	}

	return;
}