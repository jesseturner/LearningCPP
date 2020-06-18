// memoryleak

/* compile statement for command line:

g++ -std=c++11 -o memoryleak memoryleak.cpp 

*/

#include <iostream>

int main()
{
    for (int i = 0; i < 5; i++) 
    {
    	int* ptr = new int(5); 
    	std::cout << "Value: " << *ptr << " Location: " << ptr << "\n";
    	delete ptr; //Without this, it is a memory leak
    }

	return 0;
}