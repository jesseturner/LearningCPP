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

class Ball
{
		sf::CircleShape* ball; //initializing the pointer (not dereference).  

	public:
	 	Ball(int x, int y) {
			ball = new sf::CircleShape(100.0, 100.0); //returns a pointer
			ball->setPosition(x, y); //equivalent to (*ball).setPosition
		  	ball->setFillColor(sf::Color::Magenta);
		}

		void move_around(float x_speed, float y_speed, float x_angle, float y_angle) {
			ball->move(sf::Vector2f(x_angle * x_speed, y_angle * y_speed)); 
		}

		sf::CircleShape ballObj() {
			return *ball; //dereference, return the value pointed to by ball
		}
};


int main()
{
//Making the window
	sf::RenderWindow window(sf::VideoMode(1500, 1500), "Population");
	
//Making the balls

	const int numOfBalls = 5; //isn't changed. Could also use a preprocessor like #define

	Ball* ball[numOfBalls]; //declaration of class Ball
	for (int i = 0; i < numOfBalls; i++) {
	 	ball[i] = new Ball(random(1300), random(1300));
	}

//Starting animation
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
			if (evnt.type == evnt.Closed)
				window.close();


		
		for (int i = 0; i < numOfBalls; i++) {
	   	ball[i]->move_around(random(1300), random(1300), 50, 50);
	  	}


//Bouncing on each other
		/*if(ball1.getGlobalBounds().intersects(ball2.getGlobalBounds()))
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
			y_speed_3 = -y_speed_3;*/


        window.clear();
		for (int i = 0; i < numOfBalls; i++)
	   		window.draw(ball[i]->ballObj());
        window.display();
    }
}