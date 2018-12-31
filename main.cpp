#include <iostream>
#include "Bitmap.h"

using namespace akiljames;
using namespace std;

int main() {
	Bitmap bitmap(400, 300);
	bitmap.write("test.bmp");
	cout << "Finished." << endl;
	return 0;
}