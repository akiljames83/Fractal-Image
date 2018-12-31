
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace akiljames;

namespace akiljames {

Bitmap::Bitmap (int width, int height) : m_width(width), m_height(height), m_pPixels(new uint8_t [width * height * 3]{}) {
	// Brackets, {}, for the m_pPixels in initialization list sets the values to be 0 at those locations in memory

}

bool Bitmap::write(string filename) {
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;


	return false;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
	return;
}

Bitmap::~Bitmap() {

}

} /* namespace akiljames */
