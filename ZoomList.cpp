
#include "ZoomList.h"

namespace akiljames {

ZoomList::ZoomList(int width, int height)
	: m_width(width), m_height(height) {}

ZoomList::~ZoomList() {

}

void ZoomList::add(const Zoom& zoom) {
	zooms.push_back(zoom);

	
}

std::pair<double, double> ZoomList::doZoom(int x, int y) {
	return std::make_pair(0., 0.);
} 


}