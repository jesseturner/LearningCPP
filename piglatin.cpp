// piglatin generator

/* compile statement for command line:

g++ -std=c++11 -o piglatin piglatin.cpp 

*/

#include <iostream>

int main()
{
	std::string word;
	std::string first_letter;

	std::cout << "Enter word: ";
	std::cin >> word;

	first_letter = word[0];

	word.append(first_letter);
	word.append("ay");
	word.erase(word.begin());

	std::cout << word << "\n";



return 0;
}