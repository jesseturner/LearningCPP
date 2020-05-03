// recursive fractal tree

// test code from SFML website

/* compile in command line: 
g++ -o fractal_tree fractal_tree.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ 
-L~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/lib/ -lsfml-graphics -lsfml-system -lsfml-window */

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(700,700), "Fractal Tree");
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
			{
				window.close();
			}
		}

		window.draw(player);
		window.display();
	}


    return 0;
}