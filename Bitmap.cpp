
#include <fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace akiljames;
using namespace std;

namespace akiljames {

Bitmap::Bitmap (int width, int height) : 
	m_width(width), m_height(height), m_pPixels(
		new uint8_t [width * height * 3]{}) {
	// Brackets, {}, for the m_pPixels in initialization list sets the values to be 0 at those locations in memory

}

bool Bitmap::write(string filename) {
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;

	ofstream file;

	/* Writing to a binary file */
	file.open(filename.c_str(), ios::out | ios::binary);

	/* Checking to see if we can write to the file */
	if (!file)
		return false;

	/* Writing to file after casting the pointer, static cast does not work though */
	file.write((char *)&fileHeader, sizeof(fileHeader));
	file.write((char *)&infoHeader, sizeof(infoHeader));
	file.write((char *)m_pPixels.get(), m_width * m_height * 3);


	file.close();

	/* Making sure we can write to the file */
	if(!file)
		return false;

	return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
	uint8_t *pPixel = m_pPixels.get(); /* Allows you to get memory address from unique ptrs */
	pPixel += (y * 3) * m_width + (x * 3);

	/* Bitmap is of little Endian format, thats why it is order BGR instead of RGB */
	pPixel[0] =  blue;
	pPixel[1] = green;
	pPixel[2] = red;


}

Bitmap::~Bitmap() {

}

} /* namespace akiljames */
