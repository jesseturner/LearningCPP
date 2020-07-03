//Refraction and reflection

/* compile statement: 

g++ -std=c++11 -o refraction refraction.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ -lsfml-graphics -lsfml-system -lsfml-window 

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
	sf::RectangleShape ray_enter(sf::Vector2f(430.0f, 10.0f)); //can hard-code this one
	sf::RectangleShape ray_cross(sf::Vector2f(650.0f, 10.0f)); //calculate the distance across the circle from angle
	sf::RectangleShape ray_return(sf::Vector2f(500.0f, 10.0f));
	sf::RectangleShape ray_exit(sf::Vector2f(500.0f, 10.0f));

	drop.setPosition(400,400);

	ray_enter.setFillColor(sf::Color::Blue);
	ray_cross.setFillColor(sf::Color::Blue);
	ray_return.setFillColor(sf::Color::Blue);
	drop.setFillColor(sf::Color::Transparent);
	drop.setOutlineThickness(10);

	float n_one = 1;
	float n_two;
	float theta_one = 30; //in degrees
	float theta_two;


	std::cout << "Enter refraction index: " << std::endl;
	std::cin >> n_two;

	float height;
	std::cout << "Enter ray height (50-750): " << std::endl;
	std::cin >> height;

	ray_enter.setPosition(0, height);

	theta_one = deg_to_rad(theta_one);
	theta_two = asin( (n_one/n_two) * sin(theta_one) ); //sin needs rad
	theta_two = rad_to_deg(theta_two);

	std::cout << theta_two << std::endl;

	ray_cross.setPosition(430, height);
	ray_cross.setRotation(theta_two); //rotation needs deg

	float length = ((height / 400) * 700); // 400 is midpoint, 700 is diameter
	ray_return.setPosition(500, length); // x is dist across circle points
	//ray_return.setRotation(-theta_two);


//running while window is open
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
			if (evnt.type == evnt.Closed)
				window.close();

		


	    window.clear();
        window.draw(ray_enter);
        window.draw(ray_cross);
        window.draw(ray_return);
        window.draw(drop);
        window.display();
    }

return 0;
}


