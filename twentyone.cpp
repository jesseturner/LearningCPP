/* compile statement for command line (remove line break)(my library is in a terrible location): 

g++ -std=c++11 -o twentyone twentyone.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ 
-lsfml-graphics -lsfml-system -lsfml-window 

*/

#include <iostream>
#include <SFML/Graphics.hpp>

/*std::string resourcesDir()
{
#ifdef SFML_SYSTEM_IOS
    return "";
#else
    return "resources/";
#endif
}*/

int main()
{
	// Make the game window
	const int gameWidth = 800;
    const int gameHeight = 600;
	sf::RenderWindow window(sf::VideoMode(1500, 1500), "SFML Twenty-One");

    // Load the text font
    sf::Font font;
	font.loadFromFile("sansation.ttf");

	// Text settings
	sf::Text gameMessage;
	gameMessage.setFont(font);
    gameMessage.setCharacterSize(40);
    gameMessage.setPosition(500, 750);
    gameMessage.setFillColor(sf::Color::White);

    sf::Text player1;
    player1.setFont(font);
    player1.setCharacterSize(40);
    player1.setPosition(1200, 750);
    player1.setFillColor(sf::Color::White);

    sf::Text player2;
    player2.setFont(font);
    player2.setCharacterSize(40);
    player2.setPosition(750, 1200);
    player2.setFillColor(sf::Color::White);

    sf::Text player3;
    player3.setFont(font);
    player3.setCharacterSize(40);
    player3.setPosition(300, 750);
    player3.setFillColor(sf::Color::White);

    sf::Text player4;
    player4.setFont(font);
    player4.setCharacterSize(40);
    player4.setPosition(750, 300);
    player4.setFillColor(sf::Color::White);

    bool isPlaying = false;
	int count;

    while (window.isOpen())
    {
    	sf::Event evnt;
		while (window.pollEvent(evnt))
			if (evnt.type == evnt.Closed)
				window.close();
		
		if(!isPlaying)
		{
    		gameMessage.setString("Twenty-One\nPress space to start");
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) 
				{
					isPlaying = true;
					window.clear();
				}
		}
		if(isPlaying) // Play the round
		{
			gameMessage.setString("Playing"); // Seems to want this Text changed
			for (count = 1; count < 10; count++)
			{
				player1.setString(std::to_string(count));
				player2.setString(std::to_string(count));
				player3.setString(std::to_string(count));
				player4.setString(std::to_string(count));
			}
		}

		window.clear();
		window.draw(player1);
		window.draw(player2);
		window.draw(player3);
		window.draw(player4);
		window.draw(gameMessage);
    	window.display();
    }

    return EXIT_SUCCESS;
}