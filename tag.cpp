//tag game

/* compile statement for command line (remove line break)(my library is in a terrible location): 

g++ -std=c++11 -o tag tag.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ 
-lsfml-graphics -lsfml-system -lsfml-window 

*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h> //for rand

int main()
{
//Making the window
	sf::RenderWindow window(sf::VideoMode(1500, 1500), "Tag");
	float x_wall = 1500, y_wall = 1500;

//Making the player
	sf::RectangleShape player(sf::Vector2f(100.f, 100.f));
	player.setFillColor(sf::Color::Red);

//Making the items
	int x_pos, y_pos;
	sf::CircleShape item(25.f, 25.f);

//Placing the items
	// int item_number = 10; Could be the number of items
	x_pos = rand() % 1450;
	y_pos = rand() % 1450;
	item.setPosition(x_pos, y_pos);

//Initializing game
	const float Speed = 400.f ;
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
			if (evnt.type == evnt.Closed)
				window.close();

//Moving the player
		float deltaTime = clock.restart().asSeconds();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && (player.getPosition().x > 0.f))
			player.move((- Speed * deltaTime), 0.0f);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && (player.getPosition().x < 1400.f))
			player.move((Speed * deltaTime), 0.0f);	
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && (player.getPosition().y > 0.f))
			player.move(0.0f, (- Speed * deltaTime));
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && (player.getPosition().y < 1400.f))
			player.move(0.0f, (Speed * deltaTime));

//Running the items

		//some pythagorean theorem here would be good

		float player_x = player.getPosition().x, player_y = player.getPosition().y;
		float item_x = item.getPosition().x, item_y = item.getPosition().y;

		if ( (player_x < item_x) && (item_x - player_x < 300) && (item_x < 1450) )
		{
			item.move((Speed * deltaTime), 0);
		}
		if ( (player_y < item_y) && (item_y - player_y < 300) && (item_y < 1450) )
		{
			item.move(0, (Speed * deltaTime));
		}
		if ( (player_x > item_x) && (player_x - item_x < 300) && (item_x > 0) )
		{
			item.move(-(Speed * deltaTime), 0);
		}
		if ( (player_y > item_y) && (player_y - item_y < 300) && (item_y < 0) )
		{
			item.move(0, -(Speed * deltaTime));
		}
		

//Catching the item
		if(player.getGlobalBounds().intersects(item.getGlobalBounds()))
		{
			x_pos = rand() % 1450;
			y_pos = rand() % 1450;
			item.setPosition(x_pos, y_pos);
		}


//Drawing game pieces
	    window.clear();
        window.draw(player);
        window.draw(item);
        window.display();
    }
    return 0;
}

