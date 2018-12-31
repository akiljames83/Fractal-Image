
#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint> /* To specify the integer has 32 bits*/

using namespace std;

#pragma pack(2)

namespace akiljames {

struct BitmapFileHeader {
	/*
		For writing information to the bitmap file.
	*/
	char header[2]{'B','M'}; 
	int32_t fileSize;
	int32_t reserved{0};
	int32_t dataOffset;

	
};

}




#endif /* BITMAPFILEHEADER_H_ */