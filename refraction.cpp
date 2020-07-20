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
	float theta_one_rad;
	float theta_two_rad;
	float theta_two_deg;


	std::cout << "Enter refraction index: " << std::endl;
	std::cin >> n_two;

	float enter_height = 600;


//running while window is open
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
			if (evnt.type == evnt.Closed)
				window.close();


		//moving the entrance height
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			enter_height--;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			enter_height++;

		ray_enter.setPosition(0, enter_height);


		//angle from the center of the circle
		theta_one_rad = asin( (750 - enter_height) / ( 350 ) );

		//distance before hitting the circle
		float dist_to = ( ( -cos( theta_one_rad ) * 350 ) + 750); 
		float y_dist_to = ( ( sin( theta_one_rad ) * 350 ) - 750); //for reflection
		ray_enter.setSize(sf::Vector2f(dist_to, 10.0f));

		//refraction after entering
		theta_two_rad = asin( (n_one/n_two) * sin(theta_one_rad) ); //sin needs rad
		theta_two_deg = rad_to_deg(theta_two_rad);


		//ray crossing the drop, position, size, and angle
		ray_cross.setPosition(dist_to, enter_height); 
		ray_cross.setRotation(theta_two_deg);
		float dist_cross = 2 * ( 350 * sin( ( 3.1416 - theta_one_rad ) / 2 ) ); //calculating the chord distance
		ray_cross.setSize(sf::Vector2f(dist_cross, 10.0f));

		std::cout << theta_two_deg << std::endl;

		//ray returning across the drop
		float cross_x = (cos( theta_two_rad ) * dist_cross);
		float cross_y = -(sin( theta_two_rad ) * dist_cross);
		ray_return.setPosition((cross_x + dist_to), -(cross_y + y_dist_to));
		ray_return.setRotation(180 - theta_two_deg);

		float theta_three_rad = 3.1416 - ( 2 * (theta_two_rad - theta_one_rad) ); //not correct for theta_three
		float dist_return = 2 * ( 350 * sin( ( theta_three_rad ) / 2 ) );
		ray_return.setSize(sf::Vector2f( dist_return, 10.0f));


	    window.clear();
        window.draw(ray_enter);
        window.draw(ray_cross);
        window.draw(ray_return);
        window.draw(drop);
        window.display();
    }

return 0;
}


