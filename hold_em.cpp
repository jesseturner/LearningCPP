/* Texas Hold Em game, no betting */

#include <iostream> 
using namespace std; 

#include <string>
#include <vector>

#include <stdlib.h>
#include <time.h>

int main() {

//making the deck

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
	deck.push_back("Ace of Hearts"); 
	deck.push_back("Two of Hearts");
	deck.push_back("Three of Hearts");
	deck.push_back("Four of Hearts");
	deck.push_back("Five of Hearts");
	deck.push_back("Six of Hearts");
	deck.push_back("Seven of Hearts");
	deck.push_back("Eight of Hearts");
	deck.push_back("Nine of Hearts");
	deck.push_back("Ten of Hearts");
	deck.push_back("Jack of Hearts");
	deck.push_back("Queen of Hearts");
	deck.push_back("King of Hearts");
	deck.push_back("Ace of Diamonds"); 
	deck.push_back("Two of Diamonds");
	deck.push_back("Three of Diamonds");
	deck.push_back("Four of Diamonds");
	deck.push_back("Five of Diamonds");
	deck.push_back("Six of Diamonds");
	deck.push_back("Seven of Diamonds");
	deck.push_back("Eight of Diamonds");
	deck.push_back("Nine of Diamonds");
	deck.push_back("Ten of Diamonds");
	deck.push_back("Jack of Diamonds");
	deck.push_back("Queen of Diamonds");
	deck.push_back("King of Diamonds");
	deck.push_back("Ace of Clubs"); 
	deck.push_back("Two of Clubs");
	deck.push_back("Three of Clubs");
	deck.push_back("Four of Clubs");
	deck.push_back("Five of Clubs");
	deck.push_back("Six of Clubs");
	deck.push_back("Seven of Clubs");
	deck.push_back("Eight of Clubs");
	deck.push_back("Nine of Clubs");
	deck.push_back("Ten of Clubs");
	deck.push_back("Jack of Clubs");
	deck.push_back("Queen of Clubs");
	deck.push_back("King of Clubs");

//dealing the cards

	srand (time(NULL));

	int hero_1 = rand() % deck.size();
	deck.erase(deck.begin() + hero_1);

	int villain_1 = rand() % deck.size();
	deck.erase(deck.begin() + villain_1);

	int hero_2 = rand() % deck.size();
	deck.erase(deck.begin() + hero_2);

	int villain_2 = rand() % deck.size();
	deck.erase(deck.begin() + villain_2);

	cout << "Your pocket cards are: " << deck[hero_1] << " and " << deck[hero_2] << endl;

//first bet

	cout << "Place bet (Opponent will call): " << endl;

	int bet_preflop;
	cin >> bet_preflop;

	cout << "Pot size: " << bet_preflop*2 << "\n\n";

//flop

	int flop_1 = rand() % deck.size();
	deck.erase(deck.begin() + flop_1);

	int flop_2 = rand() % deck.size();
	deck.erase(deck.begin() + flop_2);

	int flop_3 = rand() % deck.size();
	deck.erase(deck.begin() + flop_3);

	cout << "Flop: " << deck[flop_1] << ", " << deck[flop_2] << ", " << deck[flop_3] << endl;

	cout << "Pocket cards: " << deck[hero_1] << " and " << deck[hero_2] << endl;


//second bet

	cout << "Place bet (Opponent will call): " << endl;

	int bet_flop;
	cin >> bet_flop;

	cout << "Pot size: " << (bet_preflop*2) + (bet_flop*2) << "\n\n";

//turn

	int turn = rand() % deck.size();
	deck.erase(deck.begin() + turn);

	cout << "Turn: " << deck[flop_1] << ", " << deck[flop_2] << ", " << deck[flop_3] << ", " << deck[turn] << endl;
	
	cout << "Pocket cards: " << deck[hero_1] << " and " << deck[hero_2] << endl;

//third bet

	cout << "Place bet (Opponent will call): " << endl;

	int bet_turn;
	cin >> bet_turn;

	cout << "Pot size: " << (bet_preflop*2) + (bet_flop*2) + (bet_turn*2) << "\n\n";

//river

	int river = rand() % deck.size();
	deck.erase(deck.begin() + river);

	cout << "River: " << deck[flop_1] << ", " << deck[flop_2] << ", " << 
	deck[flop_3] << ", " << deck[turn] << ", " << deck[river] << endl;
	
	cout << "Pocket cards: " << deck[hero_1] << " and " << deck[hero_2] << endl;

//fourth bet

	cout << "Place bet (Opponent will call): " << endl;

	int bet_river;
	cin >> bet_river;

	cout << "Pot size: " << (bet_preflop*2) + (bet_flop*2) + (bet_turn*2) + (bet_river*2) << "\n\n";


//show cards

	cout << "------------ Show cards ------------" << endl;

	cout << "Middle cards: " << deck[flop_1] << ", " << deck[flop_2] << ", " << 
	deck[flop_3] << ", " << deck[turn] << ", " << deck[river] << endl;

	cout << "Your pocket cards: " << deck[hero_1] << " and " << deck[hero_2] << endl;

	cout << "Opponent's cards: " << deck[villain_1] << " and " << deck[villain_2] << endl;

	return 0;

}