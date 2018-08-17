#ifndef ex13_19_h
#define ex13_19_h

#include <iostream>
#include <string>

using std::cout;using std::endl;using std::string;

class Employee
{
public:
	Employee(){id=++count;}
	Employee(const string& name_):name(name_){id=++count;}
	Employee(const Employee& )=delete;
	Employee& operator=(const Employee&)=delete;

	const int get_id()const{return id;}
private:
	int id;
	string name;
	static int count;
};

int Employee::count=6;

#endif
