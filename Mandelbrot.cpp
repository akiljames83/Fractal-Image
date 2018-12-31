
#include <complex>
#include "Mandelbrot.h"

using namespace std;

namespace akiljames {

Mandelbrot::Mandelbrot() {}

Mandelbrot::~Mandelbrot() {}

int Mandelbrot::getIterations(double x, double y) {

	complex<double> z = 0;
	complex<double> c(x, y);

	int iterations{};

	/* Implementing the Mandelbrot algorithm */
	while(iterations++ < MAX_ITERATIONS) {
		z = z*z + c;

		if (abs(z) > 2)
			break;
	}

	return iterations;
}

}