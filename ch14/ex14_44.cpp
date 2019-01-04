#ifndef EX14_44
#define EX14_44

#include <string>
#include <iostream>
#include <map>
#include <functional>
using std::string;
using std::cin;using std::cout;using std::endl;

int add(int i, int j){return i+j;}
class Multi
{
public: 
	int operator()(int i, int j) const 
	{ return i*j;}
};
auto mod = [](int i, int j){ return i % j;};

//auto caculator = std::map<string str, std::function<int(int, int)>> 
auto caculator = std::map<string, std::function<int(int, int)>>
{
	{"+", add},					//function pointer
	{"-", std::minus<int>()},			//library functor
	{"*", Multi()},					//user_defined functor
	{"/", [](int i, int j){ return i / j;}},	//unamed lambda
	{"%", mod}					//named lambda
};

int main()
{
	while(cout << "Input as num operator num: " << endl, true)
	{
		//input
		int lhs, rhs;
		string operator_;
		cin >> lhs >> operator_ >> rhs;
		//caculate
		auto result = caculator[operator_](lhs, rhs);
		//output
		cout << result << endl;
	}
	return 0;
}

#endif
