// drivers_license

/* compile statement for command line:

g++ -std=c++11 -o drivers_license drivers_license.cpp 

*/

#include <iostream>

class License
{

public: // note: means that these can be accessed from outside the class

	std::string name; 
	int height; 
	int weight;
	int warnings = 0;

	void add_warning()
	{
		++warnings;
	}
};

int main()
{
	License driver; // declaring object of license class
	std::cout << " Enter the driver's name: ";
	std::cin >> driver.name;
	std::cout << "\n Enter the driver's height (in inches): ";
	std::cin >> driver.height;
	std::cout << "\n Enter the driver's weight (in pounds): ";
	std::cin >> driver.weight;


	std::cout << "\n " << driver.name << " has " << driver.warnings << " warnings. \n\n";

	std::cout << " Add a warning to this account? (Y/N) ";

	std::string response;
	std::cin >> response; 

	if(response == "Y")
	{
		driver.add_warning();
		std::cout << "\n " << driver.name << " has " << driver.warnings << " warnings. \n\n";
	}

	else
		std::cout << "\n No warning added. \n\n";

return 0;
}
