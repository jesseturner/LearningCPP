//random drawing


/* compile statement for command line (remove line break)(my library is in a terrible location): 

g++ -std=c++11 -o random_circle random_circle.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ 
-lsfml-graphics -lsfml-system -lsfml-window 

*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h> //Specific to Unix systems



int main() 
{
	sf::RenderWindow window(sf::VideoMode(1500, 1500), "Random Circle");
	sf::RectangleShape line(sf::Vector2f(500.0f, 10.0f));
	srand(unsigned(time(0)));
	line.setPosition(750, 750);
	int line_number = 50;
	int i;

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
			if (evnt.type == evnt.Closed)
				window.close();

		while ( i < line_number )
		{
			int random_angle = rand() % 360;
			line.setRotation(random_angle);

	   		window.draw(line);
       		window.display();
        	//sleep(1);
        	++i;
    	}
    }

return 0;
}
