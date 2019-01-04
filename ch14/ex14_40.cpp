#ifndef EX14_40
#define EX14_40

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using std::ifstream; 
using std::vector;
using std::string; 
using std::cout; using std::endl;
using std::size_t;

class FirstBig		//find the fist position that the value is bigger enough
{
public:
	FirstBig(size_t n) : sz(n)
	{ }
	bool operator() (const string& str) const 
	{ return str.size() >= sz? true : false;}
private:
	size_t sz;
};


class OutPut		//output the result of biggies
{
public:
	void operator () (string str)
	{ cout << str << " ";}
};

class SizeSort
{
public:
	bool operator () (const string& str1, const string& str2)
	{ return str1.size() < str2.size()? true : false;}
};

void elimDups(vector<string>& vs)	//lexi sort and unique
{
	//lexi sort
	sort(vs.begin(), vs.end());
	auto unique_end = unique(vs.begin(), vs.end());
	vs.erase(unique_end, vs.end());
}

string makePlural(const string& str)	//add s for plural
{
	return str.size() > 1? str + "s" : str;
}

void biggies(vector<string>& vs, size_t sz)
{
	//lexi sort and unique
	elimDups(vs);
	stable_sort(vs.begin(), vs.end(), SizeSort());
	//find the first position that the value is bigger enough 
	auto posi = find_if(vs.begin(), vs.end(), FirstBig(sz));
	//get the the number that size >= sz
	auto result_num = vs.end() - posi;
	cout << result_num << " " << makePlural("word") << " of length " << sz << " or bigger." << endl;
	//output
	for_each(posi, vs.end(), OutPut());
}

int main()
{
	//input
	vector<string> vs;

	ifstream ifs("../data/unique.txt");
	for(string word; ifs >> word; /* */)
		vs.push_back(word);

	//sort and find the result, output the result
	biggies(vs, 5);

	return 0;
}

#endif
