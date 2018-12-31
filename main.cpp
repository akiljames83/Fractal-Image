#include <iostream>
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace akiljames;
using namespace std;

int main() {
	int const WIDTH = 400;
	int const HEIGHT = 300;
	Bitmap bitmap(WIDTH, HEIGHT);

	double min = 9999999;
	double max = -9999999;

	for (int w = 0; w < WIDTH; w++){
		for (int h = 0; h < HEIGHT; h++){
			double xFractal = ((double)w/WIDTH) * 2 - 1;
			double yFractal = ((double)h/HEIGHT) * 2 - 1;

			if (yFractal < min) min = xFractal;
			if(yFractal > max) max = xFractal;

			bitmap.setPixel(w, h, 255, 0, 100);
		}
	}

	cout << min << " , " << max << endl;

	bitmap.write("test.bmp");

	cout << "Finished." << endl;
	return 0;
}