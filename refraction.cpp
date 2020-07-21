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
	ray_exit.setFillColor(sf::Color::Blue);
	drop.setFillColor(sf::Color::Transparent);
	drop.setOutlineThickness(10);

	float n_one = 1;
	float n_two;
	float theta_one;
	float theta_two;
	float theta_three;
	float theta_four;
	float theta_five;
	float theta_six;



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



		//set angles and distances
		theta_one = asin( (750 - enter_height) / ( 350 ) ); //angle of entrance to center of circle
		theta_two = asin( (n_one/n_two) * sin(theta_one) ); //angle between incedence and refracted line
		theta_three = ( (M_PI/2) - (theta_one + theta_two));
		theta_four = ( theta_one + theta_three );
		theta_five = ((M_PI/2) - (theta_four/2));
		theta_six = asin( (n_one/n_two) * sin(theta_four) );

		float x_dist_to = ( ( -cos( theta_one ) * 350 ) + 750); 
		float y_dist_to = ( ( sin( theta_one ) * 350 ) - 750); //for reflection

		float dist_cross = std::abs( 2 * ( 350 * cos( theta_three ) ) ); //calculating the chord distance

		float cross_x = (cos( theta_two ) * dist_cross);
		float cross_y = -(sin( theta_two ) * dist_cross);

		float dist_return = 2 * ( 350 * sin( ( theta_four ) / 2 ) );
		float x_dist_exit = ((x_dist_to + cross_x) - (sin(theta_four) * 350));
		float y_dist_exit = ((y_dist_to + cross_y) + (cos(theta_four) * 350));



		
		ray_enter.setPosition(0, enter_height);
		ray_enter.setSize(sf::Vector2f(x_dist_to, 10.0f));

		float theta_two_deg = rad_to_deg(theta_two);

		ray_cross.setPosition(x_dist_to, enter_height); 
		ray_cross.setRotation(theta_two_deg);
		ray_cross.setSize(sf::Vector2f(dist_cross, 10.0f));

		float theta_three_deg = rad_to_deg(theta_three);
		float theta_four_deg = rad_to_deg(theta_four);


		ray_return.setPosition((cross_x + x_dist_to), -(cross_y + y_dist_to));
		ray_return.setRotation( 180 - theta_two_deg);
		ray_return.setSize(sf::Vector2f( dist_return, 10.0f));

		ray_exit.setPosition(x_dist_exit, y_dist_exit);
		ray_exit.setRotation(180);
		ray_exit.setSize(sf::Vector2f( 400.f, 10.f ));


	    window.clear();
        window.draw(ray_enter);
        window.draw(ray_cross);
        window.draw(ray_return);
        window.draw(ray_exit);
        window.draw(drop);
        window.display();
    }

return 0;
}


