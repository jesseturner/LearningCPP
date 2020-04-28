/* Texas Hold Em game, no betting */

#include <iostream> 
using namespace std; 

#include <string>
#include <vector>

#include <stdlib.h>
#include <time.h>

int main() {

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

	int dealt_1 = rand() % deck.size();
	deck[dealt_1];

	deck.erase(deck.begin() + dealt_1);

	cout << "First randomly drawn card: " << deck[dealt_1] << endl;

	return 0;
}