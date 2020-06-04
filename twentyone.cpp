/* compile statement for command line:

g++ -std=c++11 -o twentyone twentyone.cpp 

*/

#include <iostream>
#include <ctime>

// Without graphics

int main()
{
	int round[21] = {1, 2, 3, 4, 5};
	std::string count[21] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21"};
	int change_number;
	std::string new_count;
	int swap_1;
	int swap_2;
	std::string temp;

	for (int i = 1; i < 6; i++)
	{
		for (int a = 0; a < 21; a++)
		{
				std::cout << count[a] << "\n";
		}

		std::cout << "\n" << "Which number to alter: ";
		std::cin >> change_number;
		std::cout << " \n Change " << change_number << " to: " ;
		std::cin >> new_count;
		count[change_number-1] = new_count;
		std::cout << change_number << " is now " << count[change_number-1] << "\n\n";

		std::cout << "\n" << "Which positions to swap: ";
		std::cin >> swap_1; 
		std::cout << "Swap " << swap_1 << " with: ";
		std::cin >> swap_2;

		// swap logic
		temp = count[swap_1-1];
		count[swap_1-1] = count[swap_2-1];
		count[swap_2-1] = temp;

		std::cout << count[swap_1-1] << " and " << count[swap_2-1] << " are swapped." << "\n\n";


	}

	return 0;
}