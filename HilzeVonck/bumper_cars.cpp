//bumper cars

/* compile statement for command line (remove line break)(my library is in a terrible location): 

g++ -std=c++11 -o bumper_cars bumper_cars.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ 
-lsfml-graphics -lsfml-system -lsfml-window 

*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>
#include <chrono>
//#include "Collider.hpp"


int main()
{
//Making the window
	sf::RenderWindow window(sf::VideoMode(1500, 1500), "Bumper Cars");
	sf::RectangleShape player1(sf::Vector2f(100.0f, 100.0f)); //f is float (also i for int or u for undef)
	sf::RectangleShape player2(sf::Vector2f(100.0f, 100.0f));
	player1.setFillColor(sf::Color::Red);
	player2.setFillColor(sf::Color::Blue);
	player2.setPosition(1400, 1400);

	const float Speed = 400.f ;
	sf::Clock clock;
	bool isColliding1 = false;
	bool isColliding2 = false;

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
			if (evnt.type == evnt.Closed)
				window.close();


//Driving the cars
		float deltaTime = clock.restart().asSeconds();
		if(!isColliding1)
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && (player1.getPosition().x > 0.f))
				player1.move((- Speed * deltaTime), 0.0f);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && (player1.getPosition().x < 1400.f))
				player1.move((Speed * deltaTime), 0.0f);	
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && (player1.getPosition().y > 0.f))
				player1.move(0.0f, (- Speed * deltaTime));
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && (player1.getPosition().y < 1400.f))
				player1.move(0.0f, (Speed * deltaTime));
		}

		if(!isColliding2)
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && (player2.getPosition().x > 0.f))
				player2.move((- Speed * deltaTime), 0.0f);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && (player2.getPosition().x < 1400.f))
				player2.move((Speed * deltaTime), 0.0f);		
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && (player2.getPosition().y > 0.f))
				player2.move(0.0f, (- Speed * deltaTime));
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && (player2.getPosition().y < 1400.f))
				player2.move(0.0f,(Speed * deltaTime));
		}

//Bumping the walls
		/*if((player1.getPosition().x > 0.f) || (player1.getPosition().x < 1400.f) || (player1.getPosition().y > 0.f) || (player1.getPosition().y < 1400.f))
			isColliding1 = true;

		if((player2.getPosition().x > 0.f) || (player2.getPosition().x < 1400.f) || (player2.getPosition().y > 0.f) || (player2.getPosition().y < 1400.f))
			isColliding2 = true;
*/
//Bumping the cars
		if(player1.getGlobalBounds().intersects(player2.getGlobalBounds()))
			{
				isColliding1 = true;
				isColliding2 = true;
			}

//Collision
		if(isColliding1)
		{
			player1.move(-2.0f, 2.0f);
			player1.setFillColor(sf::Color::Green);
		}

		if(isColliding2)
		{
			player2.move(2.0f, -2.0f);
			player2.setFillColor(sf::Color::Green);
		}


        window.clear();
        window.draw(player1);
        window.draw(player2);
        window.display();
	}


    return 0;
}