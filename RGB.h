
#ifndef RGB_H_
#define RGB_H_

namespace akiljames {

struct RGB {
public:
	double r;
	double g;
	double b;

public:
	RGB(double r, double b, double g);
};
RGB operator-(const RGB&, const RGB& second)
}

#endif