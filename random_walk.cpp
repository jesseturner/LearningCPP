//random walk
/* compile statement for command line: 

g++ -std=c++11 -o random_walk random_walk.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ -lsfml-graphics -lsfml-system -lsfml-window 

*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

int main()
{
	int distance = 10;
	
	sf::RenderWindow window(sf::VideoMode(1500, 1500), "Random Walk");
	sf::RectangleShape player(sf::Vector2f(10.0f, 10.0f));
	player.setPosition(790,790);

	/*window.setFramerateLimit(60);
		
	while (window.isOpen())
		{
			sf::Event evnt;
			while (window.pollEvent(evnt))
				if (evnt.type == evnt.Closed)
					window.close();*/
			srand((unsigned)time(NULL)); 
			



		for(int i = 0; i < distance; i++){
			int direction = rand() % 4;
	   		
	   		if (direction == 0)
	   			player.move(10.0f, 0.0f);
	   		if (direction ==1)
	   			player.move(-10.0f, 0.0f);
	   		if (direction == 2)
	   			player.move(0.0f, 10.0f);
	   		if (direction == 3)
	   			player.move(0.0f, -10.0f);

	   	//std::cout << direction << std::endl;

	   	std::cout << player.getPosition().x << ", " << player.getPosition().y << std::endl;

	   		
		}
	//window.clear();
	window.draw(player);
	window.display();
	}
