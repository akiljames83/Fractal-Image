#include "FractalCreator.h"

using namespace akiljames;
using namespace std;

int main() {
	int const m_width = 800;
	int const m_height = 600;

	FractalCreator fractalCreator(m_width, m_height);

	fractalCreator.addZoom(Zoom(365, m_height - 134, 0.1));
    fractalCreator.addZoom(Zoom(404, m_height- 246, 0.3));

    fractalCreator.calculateIteration();
    fractalCreator.calculateTotalIteration();
    fractalCreator.drawFractal();

    fractalCreator.writeBitmap("test3.bmp");
    cout << "Finished program." << endl;

	return 0;

}
// int main() {






// 	

// 	cout << "Finished." << endl;
// 	return 0;
// }


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