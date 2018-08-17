#ifndef ex13_18_h
#define ex13_18_h

#include <iostream>
#include <string>

using std::cout;using std::endl;using std::string;

class Employee
{
public:
	Employee(){id=++count;}
	Employee(const string& name_):name(name_){id=++count;}
	const int get_id()const{return id;}
private:
	int id;
	string name;
	static int count;
};

int Employee::count=6;

#endif
