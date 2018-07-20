#ifndef EX7_53_H
#define EX7_53_H

class Debug
{
public:
	constexpr Debug(bool b=true):rt(b),io(b),other(b){}
	constexpr Debug(bool r,bool i,bool o):rt(r),io(i),other(o){}
	constexpr bool any(){return rt||io||other;}
	
	void set_rt(bool b){rt=b;}
	void set_io(bool b){io=b;}
	void set_other(bool b){other=b;}

private:
	bool rt;
	bool io;
	bool other;
}; 
#endif
