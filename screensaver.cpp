//screensaver

/* compile statement for command line (remove line break)(my library is in a terrible location): 

g++ -std=c++11 -o screensaver screensaver.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ 
-lsfml-graphics -lsfml-system -lsfml-window 

*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>

int main()
{
//Making the window
	sf::RenderWindow window(sf::VideoMode(1500, 1500), "Bumper Cars");

//Making variables
	sf::CircleShape ball1(100.0, 100.0); //f is float (also i for int or u for undef)
	sf::CircleShape ball2(100.0, 100.0);

	ball2.setPosition(1300, 1300);

	ball1.setFillColor(sf::Color::Red);
	ball2.setFillColor(sf::Color::Blue);

	float x_speed_1 = 200.f;
	float y_speed_1 = 200.f;
	float x_speed_2 = -200.f;
	float y_speed_2 = -200.f;

	sf::Clock clock;
	bool isColliding1 = false;
	bool isColliding2 = false;


//Starting animation
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
			if (evnt.type == evnt.Closed)
				window.close();
		
		float deltaTime = clock.restart().asSeconds();

		ball1.move(x_speed_1 * deltaTime, y_speed_1 * deltaTime);
		ball2.move(-x_speed_2 * deltaTime, -y_speed_2 * deltaTime);

		if(ball1.getPosition().x == 0.f)
			x_speed_1 = -x_speed_1;
		if(ball1.getPosition().x == 1300.f)
			x_speed_1 = -x_speed_1;
		if(ball1.getPosition().y == 0.f) 
			y_speed_1 = -y_speed_1;
		if(ball1.getPosition().y == 1300.f)
			y_speed_1 = -y_speed_1;




        window.clear();
        window.draw(ball1);
        window.draw(ball2);
        window.display();
    }
}