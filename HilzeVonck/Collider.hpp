#include <iostream>
#include <SFML/Graphics.hpp>

int IsCollision( sf::Vector2f position1, sf::Vector2f position2 )
{
	if (position1 == position2)
		std::cout << "Collision Detected";
		return 1;


	if (position1 != position2)
		return 0;
}
