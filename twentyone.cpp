/* compile statement for command line:

g++ -std=c++11 -o twentyone twentyone.cpp 

*/

#include <iostream>
#include <ctime>

// Without graphics

int main()
{
	int round;
	int  count;
	int change_number;
	int new_number;

	for (round = 1; round < 5; round++)
	{
		for (count = 1; count < 22; count++)
		{
			std::cout << count << "\n";
		}

		std::cout << "\n" << "Which number to alter: ";

		std::cin >> change_number;

		std::cout << " \n Change " << change_number << " to: " ;

		std::cin >> new_number;

		std::cout << change_number << " is now " << new_number << "\n\n";

	}

	return 0;
}