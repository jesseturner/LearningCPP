// recursive fractal tree

// heavily copied from alseether via SO

/* compile statement for command line (remove line break)(my library is in a terrible location): 
g++ -std=c++11 -o fractal_tree fractal_tree.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ 
-L~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/lib/ -lsfml-graphics -lsfml-system -lsfml-window */


#include <SFML/Graphics.hpp>
#include <math.h> 

const double PI = 3.141592;
const double R = 0.57;  // Reduction factor
const double O = 45;    // Degree rotation each time
sf::Color treeColor = sf::Color::White;

void createTreeRecursive(sf::VertexArray &tree, sf::Vector2f point, float angle, float length){
	if (length < 3) // End condition, can be modified
        return;

    // Add first point
    tree.append(sf::Vertex(point, treeColor));
    float newX = point.x + (cos((2.f * PI / 360.f) * angle) * length);
    float newY = point.y - (sin((2.f * PI / 360.f) * angle) * length);  // Minus(-) sign because we're drawing upwards
    sf::Vector2f nextPoint(newX, newY);
    // Add second point
    tree.append(sf::Vertex(nextPoint, treeColor));

    // Create sub-tree from 2nd point, rotating +45 degrees (i.e. counterclockwise), reducing length of the new branch by 0.6 factor
    createTreeRecursive(tree, nextPoint, angle + O, length * R);

    // Same with the other sub-tree, but rotating -45 (i.e. clockwise)
    createTreeRecursive(tree, nextPoint, angle - O, length * R);
}

sf::VertexArray createTree(){
    sf::VertexArray ret(sf::PrimitiveType::Lines); 
    createTreeRecursive(ret, sf::Vector2f(500, 1000), 90, 400);
    // Initial point at botton-center(250, 450), with a 90 degrees rotation, first branch length 200
    return ret;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Fractal Tree");
	
	auto tree = createTree();

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
			if (evnt.type == evnt.Closed)
				window.close();

        window.clear();
        window.draw(tree);
        window.display();
	}


    return 0;
}