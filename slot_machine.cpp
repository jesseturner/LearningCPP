// slot machine

/* compile statement for command line:

g++ -std=c++11 -o slot_machine slot_machine.cpp 

*/

#include <iostream>
#include <unistd.h> //Specific to Unix systems, used for sleep()
#include <vector> //Used to make the array

int randomfunc(int j) { 
    return rand() % j; 
}

int main()
{

std::vector<std::string> game;
game.push_back("Cherries"); 
game.push_back("Oranges");
game.push_back("Lemons");
game.push_back("Plums");
game.push_back("Watermelons");

srand(unsigned(time(0)));

for (int j = 0; j < 5; j++)
{
	for (int i = 0; i < 5; i++) 
	{
		std::random_shuffle(game.begin(), game.end(), randomfunc);
		std::cout << game[i] << " | ";
	}
	sleep(1);
	std::cout << "\n";
}


std::cout << "\n";
  

return 0;
}
