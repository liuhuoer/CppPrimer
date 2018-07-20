
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
	//set the value of a location; 
	inline Screen set(char c);
	inline Screen set(pos row,pos col,char c);
	//move to this position;
	Screen move(pos r,pos c);
	//print all values in contents;	
	Screen display(ostream & os)			//here
	{
		do_display(os);
		return *this;
	}
	const Screen display (ostream & os) const 
	{
		do_display(os);
		return *this;
	}

private:
	pos cursor=0;
	pos height=0,width=0;
	mutable std::string contents;
	//subfunction of display;
	void do_display(ostream & os) const {os<<contents;}
};

inline
Screen Screen::move(pos r,pos c) 
{
	pos row=r*width;
	cursor=row+c;
	return *this;
}

Screen Screen::set(char c) 
{
	contents[cursor]=c;
	return *this;
}

Screen Screen::set(pos row,pos col,char c)
{
	contents[row*width+col]=c;
	return *this;
}

char Screen::get(pos r,pos c) const
{
	pos row=r*width;
	return contents[row+c];
}

#endif
