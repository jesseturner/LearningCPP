// Mandelbrot Set

// Based off of CodingTrain's "Coding Challenge #21: Mandelbrot Set with p5.js"

/* compile statement for command line (remove line break)(my library is in a terrible location): 
g++ -std=c++11 -o mandelbrot mandelbrot.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ 
-L~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/lib/ -lsfml-graphics -lsfml-system -lsfml-window 
*/

#include <SFML/Graphics.hpp>

int main()
{
	int max_x = 200;
	int max_y = 200;

	// Create a 20x20 image filled with black color
	sf::Image image;
	image.create(max_x, max_y, sf::Color::Black);

	
	int pix_x = 0;
	int pix_y = 0;

	for (pix_x = 0; pix_x < max_x; pix_x++) {
		for (pix_y = 0; pix_y < max_y; pix_y++) {
			float a = pix_x; //I'm guessing the problem is here. CodingTrain uses a js map() function?
			float b = pix_y;

			float ca = a;
			float cb = b;

			for (int n = 0; n == 100; n++) {
				float aa = a * a - b * b;
				float bb = 2 * a * b;
				float a = aa + ca;
				float b = bb + cb;
				
				if (a + b > 16) {
					// Change pixel color
					sf::Color color = image.getPixel(pix_x, pix_y);
					color.r = 255;
					image.setPixel(pix_x, pix_y, color);
				}

			}
		}
	}

	// Save the image to a file
	if (!image.saveToFile("mandelbrot_result.png"))
    	return -1;

    return 0;
}
