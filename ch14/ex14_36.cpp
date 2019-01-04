#ifndef ex14_36
#define ex14_36

#include <iostream>
#include <vector>

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
	std::vector<std::string> vs;

	for(std::string temp; !(temp = myos()).empty(); vs.push_back(temp));

	for(auto begin : vs)
		std::cout << begin << std::endl;
	return 0;
}

#endif
