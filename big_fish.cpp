//big fish

/* compile statement for command line (remove line break)(my library is in a terrible location): 

g++ -std=c++11 -o big_fish big_fish.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ 
-lsfml-graphics -lsfml-system -lsfml-window 

*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h> 

int main()
{
//Making the window
	sf::RenderWindow window(sf::VideoMode(1500, 1500), "Bumper Cars");
	float x_wall = 1500, y_wall = 1500;

//Making the fish
	float x_size = 100, y_size = 100;
	float x_scale = 1, y_scale = 1;
	sf::RectangleShape fish(sf::Vector2f(x_size, y_size));
	fish.setFillColor(sf::Color::Red);

//Making the food
	int x_pos = 1400, y_pos = 1400;
	sf::RectangleShape food(sf::Vector2f(50.0f, 50.0f));
	food.setPosition(x_pos, y_pos);


//Initializing game
	const float Speed = 400.f ;
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
			if (evnt.type == evnt.Closed)
				window.close();

//Swimming the fish
		float deltaTime = clock.restart().asSeconds();

		x_wall = (1500.f - (fish.getSize().x * x_scale));

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && (fish.getPosition().x > 0.f))
			fish.move((- Speed * deltaTime), 0.0f);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && (fish.getPosition().x < x_wall))
			fish.move((Speed * deltaTime), 0.0f);	
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && (fish.getPosition().y > 0.f))
			fish.move(0.0f, (- Speed * deltaTime));
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && (fish.getPosition().y < 1400.f))
			fish.move(0.0f, (Speed * deltaTime));

//Eating the food
		if(fish.getGlobalBounds().intersects(food.getGlobalBounds()))
		{
			x_pos = rand() % 1400;
			y_pos = rand() % 1400;
			food.setPosition(x_pos, y_pos);
			x_scale = (x_scale + 0.1);
			y_scale = (y_scale + 0.1);
			fish.setScale(x_scale,y_scale);
		}


//Drawing game pieces
	    window.clear();
        window.draw(fish);
        window.draw(food);
        window.display();
    }
    return 0;
}