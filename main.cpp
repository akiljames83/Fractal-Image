#include "FractalCreator.h"

using namespace akiljames;
using namespace std;

int main() {
	int const m_width = 800;
	int const m_height = 600;

	FractalCreator fractalCreator(m_width, m_height);

	fractalCreator.addRange(0, RGB(255, 209, 73));
	fractalCreator.addRange(0.3, RGB(0, 0, 0)); // RGB(255, 0, 0));
	fractalCreator.addRange(0.5, RGB(0, 0, 0)); // RGB(255, 255, 0));
	fractalCreator.addRange(1., RGB(165, 2, 40)); // RGB(255, 255, 255));
	/*
	fractalCreator.addRange(0, RGB(237, 77, 154));
	fractalCreator.addRange(0.3, RGB(156, 178, 214)); // RGB(255, 0, 0));
	fractalCreator.addRange(0.5, RGB(77, 237, 152)); // RGB(255, 255, 0));
	fractalCreator.addRange(1., RGB(169, 176, 2)); // RGB(255, 255, 255));
	*/

	fractalCreator.run("test4.bmp");

    cout << "Finished program." << endl;

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