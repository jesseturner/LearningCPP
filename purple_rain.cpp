// Purple rain
// From a comment on The Coding Train. Annotations are me. 

/* compile statement: 

g++ -std=c++11 -o purple_rain purple_rain.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ -lsfml-graphics -lsfml-system -lsfml-window 

*/

//Preprocessors: 

#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <thread>

//sets a token (similar to variable) to a value
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


unsigned random(unsigned max) { //unsigned means non-negative, whole numbers. Max is the input. 
	static int seed = 22; /*static variables keep their value when they go out of scope. 
	Function can be called multiple times and the variable won't reset.*/
	srand((unsigned)time(NULL)); //creates the seed for the rand() function, without it, it'll default to srand(1)
	seed += rand() % 1000;
	srand(seed);
	return rand() % max;
}

class Drop
{
		sf::RectangleShape* drop; //initializng the pointer (not dereference). 
		int dropSpeed;
		int l, w;
	public:
	 	Drop(int x, int y, int l, int w) {
			drop = new sf::RectangleShape(sf::Vector2f(w, l)); //returns a pointer
			drop->setPosition(sf::Vector2f(x, y)); //equivalent to (*drop).setPosition
		  	drop->setFillColor(sf::Color::Magenta);
		  	dropSpeed = random(6) + 1;
		  	this->l = l; //set equal to the l outside the function?
	}
		void fall() { drop->move(sf::Vector2f(0, dropSpeed * (random(5)))); }
		void boundary() {
	 		if (drop->getPosition().y > SCREEN_HEIGHT)
	   		drop->setPosition(random(SCREEN_WIDTH), 0 - l); //length distance out of the top of the window
	}
	 	sf::RectangleShape dropObj() {
			return *drop; //dereference, return the value pointed to by drop
 	}
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Window");
	window.setFramerateLimit(120);

	const int numOfDrops = 150; //isn't changed. Could also use a preprocessor like #define

	Drop* drop[numOfDrops]; //declaration of class Drop
	for (int i = 0; i < numOfDrops; i++) {
	  	drop[i] = new Drop(random(SCREEN_WIDTH) + random(100), random(SCREEN_HEIGHT) + random(100), random(40) + 20, 3);
	}

	while (window.isOpen()) 
	{
	  	sf::Event e;
	  	while (window.pollEvent(e))
		{
	   	if (e.type == sf::Event::Closed)
	    	window.close(); //Standard SMFL "keep window open until closed" logic
	  	}

	  	for (int i = 0; i < numOfDrops; i++) {
	   	drop[i]->fall();
	   	drop[i]->boundary();
	  	}
	  
	  
		window.clear(sf::Color::Black);

		for (int i = 0; i < numOfDrops; i++)
	   	window.draw(drop[i]->dropObj()); //drawing multiple objects, will need to use this logic more

	  	window.display();

}
 
}