
#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include <string>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace std;

namespace akiljames {

class FractalCreator {
private:
	int m_width;
	int m_height;
	unique_ptr<int[]> m_histogram;
	unique_ptr<int[]> m_fractal;
	Bitmap m_bitmap;
	ZoomList m_zoomlist;
	int m_total{0};

public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();
	void run(string file);

private:
	void calculateIteration();
	void drawFractal();
	void calculateTotalIteration();
	void writeBitmap(string name);
	void addZoom(const Zoom& zoom);

};




}

#endif /* FRACTALCREATOR_H_ */