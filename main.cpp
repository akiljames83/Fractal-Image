#include <iostream>
#include <cstdint>
#include <memory>
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace akiljames;
using namespace std;

int main() {
	int const WIDTH = 800;
	int const HEIGHT = 600;
	Bitmap bitmap(WIDTH, HEIGHT);

	double min = 9999999;
	double max = -9999999;

	unique_ptr<int[]> histogram(new int [Mandelbrot::MAX_ITERATIONS]{});
	unique_ptr<int[]> fractal(new int [WIDTH*HEIGHT]{});

	for (int w = 0; w < WIDTH; w++){
		for (int h = 0; h < HEIGHT; h++){
			/* Scaling Code */
			double xFractal =  (w - (WIDTH*1.38)/2) * 2./(HEIGHT*0.85); //((double)(w - 200)/WIDTH) * 2 - 1;
			double yFractal = (h - HEIGHT/2) * 2./(HEIGHT*0.85); //((double)h/HEIGHT) * 2 - 1;


			/* Run the Mandelbrot Algorithm */
			int iterations = Mandelbrot::getIterations(xFractal, yFractal);
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
			/* Retrieve the number of iterations at pixel location */
			int iterations = fractal[h*WIDTH + w];

			uint8_t color = static_cast<uint8_t>(256 * static_cast<double>(iterations)/Mandelbrot::MAX_ITERATIONS);

			color = color * color * color * color; /* Play with this to change the way color is displayed */

			bitmap.setPixel(w, h, color, 0, 0);
			if(color < min) min = color;
			if(color > max) max = color;
		}
	}

	bitmap.write("test.bmp");

	cout << "Finished." << endl;
	return 0;
}


/*
OLD CODE FOR FRACTAL COLORING:

uint8_t color = static_cast<uint8_t>(256 * static_cast<double>(iterations)/Mandelbrot::MAX_ITERATIONS);

color = color * color * color * color;

bitmap.setPixel(w, h, color, 0, 0);
if(color < min) min = color;
if(color > max) max = color;

*/