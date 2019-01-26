#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
using std::cout;using std::endl;
using std::string;

class Base
{
public:
	void pub_mem();
	//void memfcn(Base& bas) { bas = *this;}

protected:
	int prot_mem;
private:
	char priv_mem;
};

#endif
