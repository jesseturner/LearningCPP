//screensaver

/* compile statement for command line (remove line break)(my library is in a terrible location): 

g++ -std=c++11 -o screensaver screensaver.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ 
-lsfml-graphics -lsfml-system -lsfml-window 

*/

#include <iostream>
#include <SFML/Graphics.hpp>
//#include <ctime>
//#include <cmath>

int main()
{
//Making the window
	sf::RenderWindow window(sf::VideoMode(1500, 1500), "Bumper Cars");

//Making variables
	sf::CircleShape ball1(100.0, 100.0); //f is float (also i for int or u for undef)
	sf::CircleShape ball2(100.0, 100.0);
	sf::CircleShape ball3(100.0, 100.0);

	ball2.setPosition(1300, 1300);
	ball3.setPosition(650, 650);

	float x_speed_1 = 200.f;
	float y_speed_1 = 200.f;
	float x_speed_2 = 200.f;
	float y_speed_2 = 200.f;
	float x_speed_3 = 200.f;
	float y_speed_3 = 200.f;

	sf::Clock move_clock;
	sf::Clock color_clock;

	float x_angle_1 = 1.2;
	float x_angle_2 = 2;
	float x_angle_3 = -0.5;
	float y_angle_1 = 1;
	float y_angle_2 = 1;
	float y_angle_3 = 1.5;

	sf::Color color_1(0, 0, 0);
	sf::Color color_2(0, 0, 0);
	sf::Color color_3(0, 0, 0);

	bool countUp = true;
	int colorCount = 0;
	int colorCountDown = 255;

//Starting animation
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
			if (evnt.type == evnt.Closed)
				window.close();
		
		float deltaTime = move_clock.restart().asSeconds();
		int colorTime = color_clock.getElapsedTime().asSeconds()*25;

		ball1.move(x_angle_1 * x_speed_1 * deltaTime, y_angle_1 * y_speed_1 * deltaTime);
		ball2.move(x_angle_2 * -x_speed_2 * deltaTime, y_angle_2 * -y_speed_2 * deltaTime);
		ball3.move(x_angle_3 * -x_speed_3 * deltaTime, y_angle_3 * -y_speed_3 * deltaTime);

//Changing colors
		if (countUp) //red ball
		{
			colorCount = (colorTime % 255);
			color_1.r = colorCount;
			if (colorTime == 255)
			{
				colorCount = 0;
				countUp = false;
			}

		}
		if (!countUp)
		{
			color_1.r = colorCountDown - (colorTime % 255);
			if (colorCountDown - (colorTime % 255) == 1)
			{
				countUp = true;
				colorCountDown = 255;
			}
		}
		if (countUp) //blue ball
		{
			colorCount = (colorTime % 255);
			color_2.b = colorCount;
			if (colorTime == 255)
			{
				colorCount = 0;
				countUp = false;
			}

		}
		if (!countUp)
		{
			color_2.b = colorCountDown - (colorTime % 255);
			if (colorCountDown - (colorTime % 255) == 1)
			{
				countUp = true;
				colorCountDown = 255;
			}
		}
		if (countUp) //green ball
		{
			colorCount = (colorTime % 255);
			color_3.g = colorCount;
			if (colorTime == 255)
			{
				colorCount = 0;
				countUp = false;
			}

		}
		if (!countUp)
		{
			color_3.g = colorCountDown - (colorTime % 255);
			if (colorCountDown - (colorTime % 255) == 1)
			{
				countUp = true;
				colorCountDown = 255;
			}
		}


		ball1.setFillColor(color_1);
		ball2.setFillColor(color_2);
		ball3.setFillColor(color_3);


//Bouncing on walls
		if(ball1.getPosition().x <= 0)
			x_speed_1 = -x_speed_1;
		if(ball1.getPosition().x >= 1300)
			x_speed_1 = -x_speed_1;
		if(ball1.getPosition().y <= 0) 
			y_speed_1 = -y_speed_1;
		if(ball1.getPosition().y >= 1300)
			y_speed_1 = -y_speed_1;

		if(ball2.getPosition().x <= 0)
			x_speed_2 = -x_speed_2;
		if(ball2.getPosition().x >= 1300)
			x_speed_2 = -x_speed_2;
		if(ball2.getPosition().y <= 0) 
			y_speed_2 = -y_speed_2;
		if(ball2.getPosition().y >= 1300)
			y_speed_2 = -y_speed_2;

		if(ball3.getPosition().x <= 0)
			x_speed_3 = -x_speed_3;
		if(ball3.getPosition().x >= 1300)
			x_speed_3 = -x_speed_3;
		if(ball3.getPosition().y <= 0) 
			y_speed_3 = -y_speed_3;
		if(ball3.getPosition().y >= 1300)
			y_speed_3 = -y_speed_3;


        window.clear();
        window.draw(ball1);
        window.draw(ball2);
        window.draw(ball3);
        window.display();
    }
}