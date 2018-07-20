
#ifndef EX7_24_H
#define EX7_24_H
#include <iostream>
#include <string>

using std::ostream;

class Screen
{
public:
	//hide the type;
	using pos=std::string::size_type;
	//three constructor;
	Screen()=default;
	Screen(pos ht,pos wd):height(ht),width(wd),contents(ht*wd,' '){}
	Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){}
	//get the value of a location;
	char get() const{return contents[cursor];}
	inline char get(pos ht,pos wd)const;
	//move to this position;
	Screen & move(pos r,pos c);

private:
	pos cursor=0;
	pos height=0,width=0;
	mutable std::string contents;
};

inline
Screen & Screen::move(pos r,pos c) 
{
	pos row=r*width;
	cursor=row+c;
	return *this;
}

char Screen::get(pos r,pos c) const
{
	pos row=r*width;
	return contents[row+c];
}

#endif
