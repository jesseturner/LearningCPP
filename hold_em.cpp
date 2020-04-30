/* Texas Hold Em game */

#include <iostream> 
using namespace std; 

#include <string>
#include <vector>

#include <stdlib.h>
#include <time.h>

#include <random>
#include <algorithm>

int randomfunc(int j) { 
    return rand() % j; 
}

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

	srand(unsigned(time(0)));

	std::random_shuffle(deck.begin(), deck.end(), randomfunc);
	
//dealing the cards

	cout << "------------ First two cards down ------------ \n\n";

	cout << "Your pocket cards are: " << deck[1] << " and " << deck[3] << "\n\n";

	cout << "Press ENTER to continue..";
	cin.ignore();
	cin.get();	

//first bet

	cout << "------------ First bet ------------ \n\n";

	cout << "Place bet (Opponent will call): " << endl;

	int bet_preflop;
	cin >> bet_preflop;

	cout << "\n\nOpponent Called \n >>> Pot size: " << bet_preflop*2 << "\n\n";

	cout << "Press ENTER to continue..";
	cin.ignore();
	cin.get();	

//flop

	cout << "------------ Flop ------------ \n\n";

	cout << "Flop: " << deck[6] << ", " << deck[7] << ", " << deck[8] << "\n\n";

	cout << "Pocket cards: " << deck[1] << " and " << deck[3] << "\n\n";

	cout << "Press ENTER to continue..";
	cin.ignore();
	cin.get();	

//second bet

	cout << "------------ Second bet ------------ \n\n";

	cout << "Place bet (Opponent will call): " << endl;

	int bet_flop;
	cin >> bet_flop;

	cout << "\n\nOpponent Called \n >>> Pot size: " << (bet_preflop*2) + (bet_flop*2) << "\n\n";

	cout << "Press ENTER to continue..";
	cin.ignore();
	cin.get();	

//turn

	cout << "------------ Turn ------------ \n\n";

	cout << "Turn: " << deck[6] << ", " << deck[7] << ", " << deck[8] << ", " << deck[10] << "\n\n";
	
	cout << "Pocket cards: " << deck[1] << " and " << deck[3] << "\n\n";

	cout << "Press ENTER to continue..";
	cin.ignore();
	cin.get();	

//third bet

	cout << "------------ Third bet ------------ \n\n";

	cout << "Place bet (Opponent will call): " << endl;

	int bet_turn;
	cin >> bet_turn;

	cout << "\n\nOpponent Called \n >>> Pot size: " << (bet_preflop*2) + (bet_flop*2) + (bet_turn*2) << "\n\n";

	cout << "Press ENTER to continue..";
	cin.ignore();
	cin.get();	

//river

	cout << "------------ River ------------ \n\n";

	cout << "River: " << deck[6] << ", " << deck[7] << ", " << 
	deck[8] << ", " << deck[10] << ", " << deck[12] << "\n\n";
	
	cout << "Pocket cards: " << deck[1] << " and " << deck[3] << "\n\n";
	
	cout << "Press ENTER to continue..";
	cin.ignore();
	cin.get();	

//fourth bet

	cout << "------------ Fourth bet ------------ \n\n";

	cout << "Place bet (Opponent will call): " << endl;

	int bet_river;
	cin >> bet_river;

	cout << "\n\nOpponent Called \n >>> Pot size: " << (bet_preflop*2) + (bet_flop*2) + 
	(bet_turn*2) + (bet_river*2) << "\n\n";

	cout << "Press ENTER to continue..";
	cin.ignore();
	cin.get();

//show cards

	cout << "------------ Show cards ------------" << "\n\n";

	cout << "Middle cards: " << deck[6] << ", " << deck[7] << ", " << 
	deck[8] << ", " << deck[10] << ", " << deck[12] << "\n\n";

	cout << "Your pocket cards: " << deck[1] << " and " << deck[3] << "\n\n";

	cout << "Opponent's cards: " << deck[2] << " and " << deck[4] << "\n\n";


	return 0;
}