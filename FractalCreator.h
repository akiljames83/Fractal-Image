
#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include <string>
#include <vector>
#include <assert.h>
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

	vector <int> m_ranges;
	vector<RGB> m_colors;
	vector <int> m_rangeTotals;

	bool m_bGotFirstRange{false};

public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();
	void run(string file);
	void addRange(double rangeEnd, const RGB& rgb);

private:
	void calculateIteration();
	void drawFractal();
	void calculateTotalIteration();
	void calculateRangeTotals();
	void writeBitmap(string name);
	void addZoom(const Zoom& zoom);
	int getRange(int iterations) const;
	

};




}

#endif /* FRACTALCREATOR_H_ */