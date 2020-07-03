//Refraction and reflection

/* compile statement: 

g++ -std=c++11 -o refraction2 refraction2.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ -lsfml-graphics -lsfml-system -lsfml-window 

*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath> //trig functions

float deg_to_rad(float deg)
{
    return deg * M_PI / 180.0;
}

float rad_to_deg(float rad)
{
    return rad / M_PI * 180.0;
}

int main() 
{

//window and variables
	sf::RenderWindow window(sf::VideoMode(1500, 1500), "Refraction and Reflection");

	sf::CircleShape drop(350.0f);
	sf::RectangleShape ray(sf::Vector2f(10.0f, 10.0f));
	//moving ray square instead of lines

	drop.setPosition(400,400);

	ray.setFillColor(sf::Color::Blue);
	drop.setFillColor(sf::Color::Transparent);
	drop.setOutlineThickness(10);

	float n_one = 1;
	float n_two;
	float theta_one = 30; //in degrees
	float theta_two;


	std::cout << "Enter refraction index: " << std::endl;
	std::cin >> n_two;

	float height;
	std::cout << "Enter ray height (400-1100): " << std::endl;
	std::cin >> height;

	ray.setPosition(0, height);

	theta_one = deg_to_rad(theta_one);
	theta_two = asin( (n_one/n_two) * sin(theta_one) ); //sin needs rad
	theta_two = rad_to_deg(theta_two);

	std::cout << theta_two << std::endl;
	
	bool Entrance = false;
	bool Bounce = false;


//running while window is open
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
			if (evnt.type == evnt.Closed)
				window.close();


		if(ray.getGlobalBounds().intersects(drop.getGlobalBounds()))
		{
			Entrance = true;
		}

		if(!Entrance)
		{
			ray.move(20.0f, 0.0f);
		}

		if(Entrance)
		{
			ray.move(15.0f, 10.0f); //arbitrary numbers, needs angle-based
			if(!ray.getGlobalBounds().intersects(drop.getGlobalBounds()))
				Bounce = true;
		}

		if(Bounce)
		{
			ray.move(-20.0f, 0.0f);
		}


        window.draw(ray);
        window.draw(drop);
        window.display();
    }

return 0;
}


