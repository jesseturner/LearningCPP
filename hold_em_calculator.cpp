/* program that calculates Texas Hold Em odds */

#include <iostream> 
using namespace std; 

#include <string>
#include <vector>

#include <stdlib.h>
#include <time.h>

int main() {

/* Needs to take an input of two cards, and compare them to the deck */

	string pocket_one;
	string pocket_two;

	cout << "Enter your first pocket card: \n";
	getline(std::cin, pocket_one);
	cout << "Enter your second pocket card: \n";
	getline(std::cin, pocket_two);


	cout << "Your cards are " << pocket_one << ", " << pocket_two << endl;

	std::vector<std::string> deck;
	deck.push_back("Ace of Spades"); 
	deck.push_back("Two of Spades");
	deck.push_back("Three of Spades");
	deck.push_back("Four of Spades");
	deck.push_back("Five of Spades");
	deck.push_back("Six of Spades");
	deck.push_back("Seven of Spades");
	deck.push_back("Eight of Spades");
	deck.push_back("Nine of Spades");
	deck.push_back("Ten of Spades");
	deck.push_back("Jack of Spades");
	deck.push_back("Queen of Spades");
	deck.push_back("King of Spades");

	srand (time(NULL));

	// deck.erase(deck.begin() + pocket_one);

	int randomIndex = rand() % deck.size();
	deck[randomIndex];

	cout << "First randomly drawn card: " << deck[randomIndex] << endl;

	return 0;
}