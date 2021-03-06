#ifndef ex13_5_h
#define ex13_5_h

#include <string>
#include <iostream>
using std::cout;using std::endl;

class HasPtr
{
public:
	HasPtr(const std::string &s=std::string()):ps(new std::string(s)),i(0){ }
	HasPtr(const HasPtr & hp):ps(new std::string(*hp.ps)),i(hp.i){ }
	printOther(const HasPtr & hp){cout<<*hp.ps<<" "<<hp.i<<endl;}
private:
	std::string *ps;
	int i;
};
#endif
