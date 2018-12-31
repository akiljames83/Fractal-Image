
#include "ZoomList.h"

using namespace std;

namespace akiljames {

ZoomList::ZoomList(int width, int height)
	: m_width(width), m_height(height) {}

ZoomList::~ZoomList() {

}

void ZoomList::add(const Zoom& zoom) {
	zooms.push_back(zoom);

	m_xCenter += (zoom.x - m_width / 2) * m_scale;
	m_yCenter += (zoom.y - m_height / 2) * m_scale;

	m_scale *= zoom.scale;

	cout << m_xCenter << " , " << m_yCenter << " , " << m_scale << endl;
}

std::pair<double, double> ZoomList::doZoom(int x, int y) {
	return std::make_pair(0., 0.);
} 


}