#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using std::string;

class Shape
{
public:
	typedef std::pair<double, double> Coordinate;

	Shape() = default;
	Shape(const string& name_) : name(name_)
	{ }
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	
	virtual ~Shape() = default;
private:
	string name;
};

#endif
