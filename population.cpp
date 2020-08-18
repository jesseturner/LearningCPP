//population

/* compile statement for command line (remove line break)(my library is in a terrible location): 

g++ -std=c++11 -o population population.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ -lsfml-graphics -lsfml-system -lsfml-window 

*/


#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>


unsigned random(unsigned max) { //unsigned means non-negative, whole numbers. Max is the input. 
	static int seed = 22; /*static variables keep their value when they go out of scope. 
	Function can be called multiple times and the variable won't reset.*/
	srand((unsigned)time(NULL)); //creates the seed for the rand() function, without it, it'll default to srand(1)
	seed += rand() % 1000;
	srand(seed);
	return rand() % max;
}


int main()
{
//Making the window
	sf::RenderWindow window(sf::VideoMode(1500, 1500), "Population");
	
	/*const int numOfPop = 5; //isn't changed. Could also use a preprocessor like #define

	for (int i = 0; i < numOfPop; i++) {
	  	ball[i] = new sf::CircleShape(100.0, 100.0);
	  	ball[i].setPosition(random(1300), random(1300));
		}*/

//Making variables
	sf::CircleShape ball1(100.0, 100.0); //f is float (also i for int or u for undef)
	sf::CircleShape ball2(100.0, 100.0);
	sf::CircleShape ball3(100.0, 100.0);

	ball1.setPosition(random(1300), random(1300));
	ball2.setPosition(random(1300), random(1300));
	ball3.setPosition(random(1300), random(1300));

	float x_speed_1 = 200.f;
	float y_speed_1 = 200.f;
	float x_speed_2 = 200.f;
	float y_speed_2 = 200.f;
	float x_speed_3 = 200.f;
	float y_speed_3 = 200.f;

	sf::Clock move_clock;

	float x_angle_1 = 1.2;
	float x_angle_2 = 2;
	float x_angle_3 = -0.5;
	float y_angle_1 = 1;
	float y_angle_2 = 1;
	float y_angle_3 = 1.5;

//Starting animation
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
			if (evnt.type == evnt.Closed)
				window.close();
		
		float deltaTime = move_clock.restart().asSeconds();

		ball1.move(x_angle_1 * x_speed_1 * deltaTime, y_angle_1 * y_speed_1 * deltaTime);
		ball2.move(x_angle_2 * -x_speed_2 * deltaTime, y_angle_2 * -y_speed_2 * deltaTime);
		ball3.move(x_angle_3 * -x_speed_3 * deltaTime, y_angle_3 * -y_speed_3 * deltaTime);

//Bouncing on each other
		if(ball1.getGlobalBounds().intersects(ball2.getGlobalBounds()))
			{
				x_speed_1 = -x_speed_1;
				y_speed_1 = -y_speed_1;

				x_speed_2 = -x_speed_2;
				y_speed_2 = -y_speed_2;
			}
		if(ball2.getGlobalBounds().intersects(ball3.getGlobalBounds()))
			{
				x_speed_3 = -x_speed_3;
				y_speed_3 = -y_speed_3;

				x_speed_2 = -x_speed_2;
				y_speed_2 = -y_speed_2;
			}
		if(ball1.getGlobalBounds().intersects(ball3.getGlobalBounds()))
			{
				x_speed_3 = -x_speed_3;
				y_speed_3 = -y_speed_3;

				x_speed_1 = -x_speed_1;
				y_speed_1 = -y_speed_1;
			}

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