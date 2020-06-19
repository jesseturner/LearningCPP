// clock

/* compile statement for command line:

g++ -std=c++11 -o ticktock ticktock.cpp 

*/

#include <iostream>
#include <unistd.h> //Specific to Unix systems


int main() 
{
	int i = 0;

	while (i < 5)
	{
		std::cout << "Tick\n";
		sleep(1);
		std::cout << "Tock\n";
		sleep(1);
		i++;
	}

return 0;
}
