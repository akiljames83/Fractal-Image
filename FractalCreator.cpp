
#include "FractalCreator.h"

namespace akiljames {

FractalCreator::FractalCreator(int width, int height) 
	: m_width(width), m_height(height), m_histogram(new int [Mandelbrot::MAX_ITERATIONS]{}),
	m_fractal(new int [width*height]{}), m_bitmap(width, height), m_zoomlist(width, height), m_total(0)
{
	m_zoomlist.add(Zoom(m_width/2, m_height/2, 4./m_width));
}

FractalCreator::~FractalCreator() {

}
void FractalCreator::run(string file) {
	addZoom(Zoom(365, m_height - 134, 0.1));
    addZoom(Zoom(404, m_height- 246, 0.3));

    calculateIteration();
    calculateTotalIteration();
    drawFractal();

    writeBitmap(file);
}
void FractalCreator::calculateIteration() {
	for (int w = 0; w < m_width; w++){
		for (int h = 0; h < m_height; h++){
			/* Scaling Code */
			pair<double, double> coords = m_zoomlist.doZoom(w, h);

			/* Run the Mandelbrot Algorithm */
			int iterations = Mandelbrot::getIterations(coords.first, coords.second);
			m_fractal[h*m_width + w] = iterations;

			/* Store the values in a histogram */
			if(iterations != Mandelbrot::MAX_ITERATIONS )
				m_histogram[iterations]++;
			
		}
	}
}
void FractalCreator::calculateTotalIteration() {
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		m_total += m_histogram[i];
	}

}
void FractalCreator::drawFractal() {
	for (int w = 0; w < m_width; w++){
		for (int h = 0; h < m_height; h++){

			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			/* Retrieve the number of iterations at pixel location */
			int iterations = m_fractal[h*m_width + w];

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				/* Generate hue of the pixel based on number of other pixels that had less than this many iterations */
				double hue = 0.;

				for (int i = 0; i <= iterations; i++)
					hue += static_cast<double>(m_histogram[i])/m_total;

				red = hue * 255;
				blue = hue * 255 / 4;
			}

			m_bitmap.setPixel(w, h, red, green, blue);
			
		}
	}
}

void FractalCreator::writeBitmap(string name) {
	m_bitmap.write(name);
}

void FractalCreator::addZoom(const Zoom& zoom) {
	m_zoomlist.add(zoom);
}


}

// int main() {
// 	int const WIDTH = 800;
// 	int const HEIGHT = 600;
// 	Bitmap bitmap(WIDTH, HEIGHT);

	
// 	ZoomList zoomlist(WIDTH, HEIGHT);

// 	zoomlist.add(Zoom(WIDTH/2, HEIGHT/2, 4./WIDTH)); /* 4 is defualt (365, 134) */ 
// 	zoomlist.add(Zoom(365, HEIGHT - 134, 0.1));
// 	zoomlist.add(Zoom(404, HEIGHT- 246, 0.3));

// 	unique_ptr<int[]> histogram(new int [Mandelbrot::MAX_ITERATIONS]{});
// 	unique_ptr<int[]> fractal(new int [WIDTH*HEIGHT]{});

// 	for (int w = 0; w < WIDTH; w++){
// 		for (int h = 0; h < HEIGHT; h++){
// 			/* Scaling Code */
// 			pair<double, double> coords = zoomlist.doZoom(w, h);

// 			/* Run the Mandelbrot Algorithm */
// 			int iterations = Mandelbrot::getIterations(coords.first, coords.second);
// 			fractal[h*WIDTH + w] = iterations;

// 			/* Store the values in a histogram */
// 			if(iterations != Mandelbrot::MAX_ITERATIONS )
// 				histogram[iterations]++;
			
// 		}
// 	}

// 	int total = 0;
// 	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
// 		total += histogram[i];
// 	}

// 	for (int w = 0; w < WIDTH; w++){
// 		for (int h = 0; h < HEIGHT; h++){

// 			uint8_t red = 0;
// 			uint8_t green = 0;
// 			uint8_t blue = 0;

// 			/* Retrieve the number of iterations at pixel location */
// 			int iterations = fractal[h*WIDTH + w];

// 			if (iterations != Mandelbrot::MAX_ITERATIONS) {
// 				/* Generate hue of the pixel based on number of other pixels that had less than this many iterations */
// 				double hue = 0.;

// 				for (int i = 0; i <= iterations; i++)
// 					hue += static_cast<double>(histogram[i])/total;

// 				red = pow(255, hue);
// 				blue = pow(127, hue);
// 			}



// 			bitmap.setPixel(w, h, red, green, blue);
			
// 		}
// 	}

// 	bitmap.write("test2.bmp");

// 	cout << "Finished." << endl;
// 	return 0;
// }