//
//  main.cpp
//  ray_square
//
//  Created by Jesse Turner on 8/13/20.
//  Copyright © 2020 Jesse Turner. All rights reserved.
//

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

    float x_cross = 350;
    
    sf::RectangleShape lens(sf::Vector2f(x_cross, 1500.0f));
    sf::RectangleShape ray_enter(sf::Vector2f(0.0f, 10.0f));
    sf::RectangleShape ray_cross(sf::Vector2f(0.0f, 10.0f));
    sf::RectangleShape ray_return(sf::Vector2f(0.0f, 10.0f));
    sf::RectangleShape ray_exit(sf::Vector2f(350.0f, 10.0f));

    lens.setPosition(400,0);

    ray_enter.setFillColor(sf::Color::Blue);
    ray_cross.setFillColor(sf::Color::Blue);
    ray_return.setFillColor(sf::Color::Blue);
    ray_exit.setFillColor(sf::Color::Blue);
    lens.setFillColor(sf::Color::Transparent);
    lens.setOutlineThickness(10);

    float n_one = 1;
    float n_two;
    
    std::cout << "Enter refraction index: " << std::endl;
    std::cin >> n_two;
    /*std::cout << "Enter incident angle (degrees):  " << std::endl;
    std::cin >> theta_one_deg;*/


//running while window is open
    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
            if (evnt.type == evnt.Closed)
                window.close();


        //moving the entrance height
        /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            enter_height--;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            enter_height++;*/



        //set angles and distances
        float enter_height = 300;
        float theta_one_deg = -30;
        while (enter_height < 1200)
        {
            float theta_one = deg_to_rad(theta_one_deg);
            float theta_two = asin( (n_one/n_two) * sin(theta_one) ); //angle between incedence and refracted line

            
            float h_to = (400 / cos(theta_one));
            float y_to = (sin(theta_one) * h_to);
        
        
            ray_enter.setPosition(0, enter_height);
            ray_enter.setRotation(theta_one_deg);
            ray_enter.setSize(sf::Vector2f(h_to, 10.0f));

            float theta_two_deg = rad_to_deg(theta_two);

            float h_cross = (x_cross / cos(theta_two));
            
            ray_cross.setPosition(400, (enter_height + y_to));
            ray_cross.setRotation(-theta_two_deg);
            ray_cross.setSize(sf::Vector2f(h_cross, 10.0f));
            
            float y_cross = -(sin(theta_two) * h_cross);
            
            ray_return.setPosition(750, (enter_height + y_to + y_cross));
            float theta_three_deg = 180 + theta_two_deg;
            ray_return.setRotation(theta_three_deg);
            float theta_three = deg_to_rad(theta_three_deg);
            float h_return = (350 / cos(theta_three));
            ray_return.setSize(sf::Vector2f(h_return, 10.0f));

            window.draw(ray_enter);
            window.draw(ray_cross);
            window.draw(ray_return);
            //window.draw(ray_exit);
                
            enter_height = enter_height+100;
            theta_one_deg = theta_one_deg+10;
        }
        //window.clear();
        window.draw(lens);
        window.display();
    }

return 0;
}


