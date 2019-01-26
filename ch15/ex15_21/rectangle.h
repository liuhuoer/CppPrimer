#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
public:
	Rectangle() = default;
	Rectangle(const string& name_, 
			const Coordinate& a_,
			const Coordinate& b_,
			const Coordinate& c_,
			const Coordinate& d_) 
		: Shape(name_), a(a_), b(b_), c(c_), d(d_)
	{ }

	double area() const
	{ return 0.0;}
	double perimeter() const
	{ return 0.0;}

	virtual ~Rectangle() = default; 
protected:
	Coordinate a;
	Coordinate b;
	Coordinate c;
	Coordinate d;
};
#endif
