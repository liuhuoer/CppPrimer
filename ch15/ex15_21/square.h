#ifndef SQUARE_H
#define SQUARE_H 

#include "shape.h"

class Square : public Rectangle
{
public:
	Square() = default;
	Square(const string& name_, 
			const Coordinate& a_,
			const Coordinate& b_,
			const Coordinate& c_,
			const Coordinate& d_) 
		: Rectangle(name_, a_, b_, c_, d_)
	{ }
	virtual ~Square() = default;

private:
};
#endif
