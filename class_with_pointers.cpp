/* compile statement for command line

g++ -std=c++11 -o class_with_pointers class_with_pointers.cpp
*/

#include <iostream>

class Trees
{
	private:
		int diameter;
		int height;

	public: 
		void TreeMetrics(int d, int h)
		{
			diameter=d;
			height=h;
		}
		int getMaxHeight()
		{
			return height*10;
		}
};

int main()
{
	Trees Birch; //Create instance of class

	Birch.TreeMetrics(25,15);
	std::cout << Birch.getMaxHeight() << "\n";

	Trees* ptr_birch = &Birch;

	std::cout << ptr_birch->getMaxHeight() << "\n";



return 0;
}