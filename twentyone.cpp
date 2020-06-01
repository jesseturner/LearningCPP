/* compile statement for command line:

g++ -std=c++11 -o twentyone twentyone.cpp 

*/

#include <iostream>
#include <ctime>

// Without graphics

int main()
{
	int round[5] = {1, 2, 3, 4, 5};
	int count[21] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
	int change_number;
	int new_number;

	for (int i = 1; i < 6; i++)
	{
		for (int a = 0; a < 21; a++)
		{
				std::cout << count[a] << "\n";
		}

		std::cout << "\n" << "Which number to alter: ";

		std::cin >> change_number;

		std::cout << " \n Change " << change_number << " to: " ;

		std::cin >> new_number;

		count[change_number-1] = new_number;
		std::cout << change_number << " is now " << count[change_number-1] << "\n\n";

	}

	return 0;
}