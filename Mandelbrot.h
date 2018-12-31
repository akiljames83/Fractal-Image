
#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace akiljames {


class Mandelbrot {
public:
	/* More iterations -> Better quality image */
	static const int MAX_ITERATIONS = 1000; 

public:
	Mandelbrot();
	virtual ~Mandelbrot();

	static int getIterations(double x, double y);

};

}
#endif /* MANDELBROT_H_ */