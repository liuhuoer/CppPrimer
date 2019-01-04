#ifndef ex14_35
#define ex14_35

#include <iostream>

class OutputString
{
public:
	OutputString(std::istream& t = std::cin) : is(t)
	{ }
	std::string operator() () const
	{ 
		std::string str;
		std::getline(is, str);
		return is ? str : std::string();
	}
	
private:
	std::istream& is;
};

int main()
{
	OutputString myos(std::cin);
	std::cout << myos() << std::endl;
	return 0;
}

#endif
