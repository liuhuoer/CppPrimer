#ifndef EX7_31_H
#define EX7_31_H

class Y;

class X
{
	Y * y=nullptr;
};

class Y
{
	X x;
};

#endif
