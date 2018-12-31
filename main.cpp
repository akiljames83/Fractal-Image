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

	// double min = 9999999;
	// double max = -9999999;
	ZoomList zoomlist(WIDTH, HEIGHT);

	zoomlist.add(Zoom(WIDTH/2, HEIGHT/2, 1));

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

				green = pow(255, hue);
			}



			bitmap.setPixel(w, h, red, green, blue);
			
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