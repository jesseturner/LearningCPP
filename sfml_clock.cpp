//SFML Clock

/* compile statement for command line (remove line break)(my library is in a terrible location): 

g++ -std=c++11 -o sfml_clock sfml_clock.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ 
-lsfml-graphics -lsfml-system -lsfml-window 

*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h> //Specific to Unix systems

int main() 
{

//compare sleep timer to the SFML clock
	sf::RenderWindow window(sf::VideoMode(1500, 1500), "SFML Clock");

	//variables
	sf::RectangleShape sec_hand(sf::Vector2f(500.0f, 10.0f));
	sf::RectangleShape min_hand(sf::Vector2f(500.0f, 10.0f));
	sf::RectangleShape hour_hand(sf::Vector2f(300.0f, 10.0f));
	sf::CircleShape face(500.0f);

	sec_hand.setPosition(750, 750);
	min_hand.setPosition(750, 750);
	hour_hand.setPosition(750, 750);
	face.setPosition(250,250);

	min_hand.setFillColor(sf::Color::Red);
	hour_hand.setFillColor(sf::Color::Blue);
	face.setFillColor(sf::Color::Transparent);
	face.setOutlineThickness(10);

	sf::Clock clock;

	//running while window is open
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
			if (evnt.type == evnt.Closed)
				window.close();

		float deltaTime = clock.getElapsedTime().asSeconds();
		
		//moving the hands
		sec_hand.setRotation(deltaTime*360);
		min_hand.setRotation(deltaTime*6);
		hour_hand.setRotation(deltaTime/10);


	    window.clear();
        window.draw(sec_hand);
        window.draw(min_hand);
        window.draw(hour_hand);
        window.draw(face);
        window.display();
    }

return 0;
}
