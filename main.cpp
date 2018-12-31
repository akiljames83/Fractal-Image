#include <iostream>
#include "Bitmap.h"

using namespace akiljames;
using namespace std;

int main() {
	int const WIDTH = 400;
	int const HEIGHT = 300;
	Bitmap bitmap(WIDTH, HEIGHT);
	for (int w = WIDTH/4; w < 3*WIDTH/4; w++){
		for (int h = HEIGHT/4; h < 3*HEIGHT/4; h++){
			bitmap.setPixel(w, h, 255, 255, 255);
		}
	}
	bitmap.write("test.bmp");

	cout << "Finished." << endl;
	return 0;
}