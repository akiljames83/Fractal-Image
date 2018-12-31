
#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include <utility>
#include <iostream>
#include "Zoom.h"

namespace akiljames {

class ZoomList {
private:
	double m_xCenter{0};
	double m_yCenter{0};
	double m_scale{0};
	int m_width{0};
	int m_height{0};
	std::vector<Zoom> zooms;

public:
	ZoomList(int m_width, int m_height);
	virtual ~ZoomList();
	void add(const Zoom& zoom);
	std::pair<double, double> doZoom(int x, int y);

};

}

#endif /* ZOOMLIST_H_ */