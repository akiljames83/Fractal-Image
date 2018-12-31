#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"

using namespace akiljames;
using namespace std;

int main() {
	int const WIDTH = 800;
	int const HEIGHT = 600;
	Bitmap bitmap(WIDTH, HEIGHT);

	
	ZoomList zoomlist(WIDTH, HEIGHT);

	zoomlist.add(Zoom(WIDTH/2, HEIGHT/2, 4./WIDTH)); /* 4 is defualt (365, 134) */ 
	zoomlist.add(Zoom(365, HEIGHT - 134, 0.1));
	zoomlist.add(Zoom(404, HEIGHT- 246, 0.3));

	unique_ptr<int[]> histogram(new int [Mandelbrot::MAX_ITERATIONS]{});
	unique_ptr<int[]> fractal(new int [WIDTH*HEIGHT]{});

	for (int w = 0; w < WIDTH; w++){
		for (int h = 0; h < HEIGHT; h++){
			/* Scaling Code */
			pair<double, double> coords = zoomlist.doZoom(w, h);

			/* Run the Mandelbrot Algorithm */
			int iterations = Mandelbrot::getIterations(coords.first, coords.second);
			fractal[h*WIDTH + w] = iterations;

			/* Store the values in a histogram */
			if(iterations != Mandelbrot::MAX_ITERATIONS )
				histogram[iterations]++;
			
		}
	}

	int total = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		total += histogram[i];
	}

	for (int w = 0; w < WIDTH; w++){
		for (int h = 0; h < HEIGHT; h++){

			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			/* Retrieve the number of iterations at pixel location */
			int iterations = fractal[h*WIDTH + w];

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				/* Generate hue of the pixel based on number of other pixels that had less than this many iterations */
				double hue = 0.;

				for (int i = 0; i <= iterations; i++)
					hue += static_cast<double>(histogram[i])/total;

				red = pow(255, hue);
				blue = pow(127, hue);
			}



			bitmap.setPixel(w, h, red, green, blue);
			
		}
	}

	bitmap.write("test2.bmp");

	cout << "Finished." << endl;
	return 0;
}


/*
OLD CODE :
// double xFractal =  (w - (WIDTH*1.38)/2) * 2./(HEIGHT*0.85); //((double)(w - 200)/WIDTH) * 2 - 1;
// double yFractal = (h - HEIGHT/2) * 2./(HEIGHT*0.85); //((double)h/HEIGHT) * 2 - 1;
// int iterations = Mandelbrot::getIterations(xFractal, yFractal);

OLDER CODE FOR FRACTAL COLORING:

// double min = 9999999;
// double max = -9999999;

uint8_t color = static_cast<uint8_t>(256 * static_cast<double>(iterations)/Mandelbrot::MAX_ITERATIONS);

color = color * color * color * color;

bitmap.setPixel(w, h, color, 0, 0);
if(color < min) min = color;
if(color > max) max = color;

*/