//bumper cars

/* compile statement for command line (remove line break)(my library is in a terrible location): 
g++ -std=c++11 -o bumper_cars bumper_cars.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ 
-L~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/lib/ -lsfml-graphics -lsfml-system -lsfml-window 
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Collider.hpp"


	/*sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }*/


int main()
{
	sf::RenderWindow window(sf::VideoMode(1500, 1500), "Bumper Cars");
	sf::RectangleShape player1(sf::Vector2f(100.0f, 100.0f)); //f is float (also i for int or u for undef)
	sf::RectangleShape player2(sf::Vector2f(100.0f, 100.0f));
	player1.setFillColor(sf::Color::Red);
	player2.setFillColor(sf::Color::Blue);

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
			if (evnt.type == evnt.Closed)
				window.close();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{ player1.move(-0.1f, 0.0f);
			void Collide(); }
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			player1.move(0.1f, 0.0f);		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			player1.move(0.0f, -0.1f);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			player1.move(0.0f, 0.1f);

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			player2.move(-0.1f, 0.0f);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			player2.move(0.1f, 0.0f);		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			player2.move(0.0f, -0.1f);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			player2.move(0.0f, 0.1f);

		//need to run this after each movement

		void Collide()
		{
			sf::Vector2f position1 = player1.getPosition();
			sf::Vector2f position2 = player2.getPosition();

			int check_col = IsCollision(position1, position2);

			if (check_col == 1)
				player1.move(-0.3f, 0.0f), player2.move(0.3f, 0.0f), 
				player1.setFillColor(sf::Color::Green), player2.setFillColor(sf::Color::Green);

			if (check_col == 0)
				player1.setFillColor(sf::Color::Red), player2.setFillColor(sf::Color::Blue);
		}
		

        window.clear();
        window.draw(player1);
        window.draw(player2);
        window.display();
	}


    return 0;
}