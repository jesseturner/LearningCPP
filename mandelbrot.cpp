// Mandelbrot Set

// Based off of CodingTrain's "Coding Challenge #21: Mandelbrot Set with p5.js"

/* compile statement for command line (remove line break)(my library is in a terrible location): 
g++ -std=c++11 -o mandelbrot mandelbrot.cpp -I~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/include/ 
-L~/Desktop/SFML\ Tut/\ExternalLibraries/SFML/lib/ -lsfml-graphics -lsfml-system -lsfml-window 
*/

#include <iostream> 
using namespace std; 
#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
	int max_x = 200;
	int max_y = 200;

	// Create a 20x20 image filled with black color
	sf::Image image;
	image.create(max_x, max_y, sf::Color::Black);

	
	int pix_x = 0;
	int pix_y = 0;
	int n = 0;

	for (pix_x = 0; pix_x < max_x; pix_x++) {
		for (pix_y = 0; pix_y < max_y; pix_y++) {
			
			//normalizing between -2 and 2
			float a = ((pix_x * 4) / (max_x)) - 2;
			float b = ((pix_y * 4) / (max_y)) - 2;

			/*float a = pix_x; //currently this gives a result, but the above should be used
			float b = pix_y;*/

			float ca = a;
			float cb = b;

			for (n = 0; n < 100; n++) {
				float aa = a * a - b * b;
				float bb = 2 * a * b;
				//cout << "a is now: " << a << "\n";
				//cout << "b is now: " << b << "\n";

				a = aa + ca;
				b = bb + cb;


				if (a + b > 16){
					// Change pixel color
					sf::Color color = image.getPixel(pix_x, pix_y);
					color.r = 255;
					image.setPixel(pix_x, pix_y, color);
				}

				/*if (isnan(a + b)){ // many nan's. Because of x/0? 
					// Change pixel color
					sf::Color color = image.getPixel(pix_x, pix_y);
					color.b = 255;
					image.setPixel(pix_x, pix_y, color);			
				}*/

			}
		}
	}

	// Save the image to a file
	if (!image.saveToFile("mandelbrot_result.png"))
    	return -1;

    return 0;
}
