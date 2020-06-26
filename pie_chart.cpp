//SFML pie chart


/* compile statement for command line (remove line break)(my library is in a terrible location): 

g++ -std=c++11 -o pie_chart pie_chart.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ 
-lsfml-graphics -lsfml-system -lsfml-window 

*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h> //Specific to Unix systems

//add values via cin, make pie chart in SFML


int main() 
{
	sf::RenderWindow window(sf::VideoMode(1500, 1500), "Pie Chart");
	sf::RectangleShape line(sf::Vector2f(500.0f, 5.0f));
	srand(unsigned(time(0)));

	line.setPosition(750, 750);

	//categories
	float red;
	float blue;
	float green;
	std::cout << "Enter the number of red: ";
	std::cin >> red;
	std::cout << "Enter the number of blue: ";
	std::cin >> blue;
	std::cout << "Enter the number of green: ";
	std::cin >> green; 

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
			if (evnt.type == evnt.Closed)
				window.close();


		float total = red + green + blue;
		float red_wedge = (red / total * 360);
		float green_wedge = ((green / total * 360) + red_wedge);
		float blue_wedge = ((blue / total * 360) + red_wedge + green_wedge);
		

		for (float i = 0; i < red_wedge; i++) {

			line.setFillColor(sf::Color::Red);
			line.setRotation(i);
			window.draw(line);
		}
		
		for (float j = red_wedge; j < green_wedge; j++) {

			line.setFillColor(sf::Color::Green);
			line.setRotation(j);
			window.draw(line);
		}

		for (float k = (red_wedge + green_wedge); k < blue_wedge; k++) {

			line.setFillColor(sf::Color::Blue);
			line.setRotation(k);
			window.draw(line);
		}

       	window.display();
    }

return 0;
}
