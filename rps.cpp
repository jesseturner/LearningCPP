//rock, paper, scissors

/* compile statement for command line:

g++ -std=c++11 -o rps rps.cpp 

*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

std::string choice;
const std::string rps_array[3] = { "rock", "paper", "scissors"};

int main()
{
	srand ( time(NULL) );  //random seed
	int RandIndex = rand() % 3;

	std::cout << "Enter your choice: rock, paper, or scissors \n";
	std::cin >> choice;

	std::cout << "Computer: " << rps_array[RandIndex] << "\n";

	if (choice == rps_array[RandIndex])
		std::cout << "TIE";
	
	if ( (choice == "rock" && rps_array[RandIndex] == "scissors") || 
		(choice == "scissors" && rps_array[RandIndex] == "paper") || 
		(choice == "paper" && rps_array[RandIndex] == "rock") )
		std::cout << "YOU WIN \n";

	if ( (choice == "rock" && rps_array[RandIndex] == "paper") || 
		(choice == "scissors" && rps_array[RandIndex] == "rock") || 
		(choice == "paper" && rps_array[RandIndex] == "scissors") )
		std::cout << "YOU LOSE \n";

return 0;
}