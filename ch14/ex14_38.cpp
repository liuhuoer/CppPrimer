#ifndef EX14_38
#define EX14_38

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>

using std::vector;using std::map;using std::string;
using std::ifstream;
using std::cout;using std::endl;
using std::size_t;

class IsEqual
{
public:
	IsEqual(size_t value) : length(value)
	{ }
	bool operator() (string word)
	{ return word.size() == length? true : false;}
	size_t getLength()
	{ return length;}

private:
	size_t length;
};

int main()
{
	//create a vector<IsEqual> with different range
	vector<IsEqual> vi;
	auto lengths = {1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u};
	for(auto length : lengths)
		vi.push_back(IsEqual{length});

	//create a map<size_t i1, size_t i2>, i1 is length of word, i2 is num
	map<size_t, size_t> count_num;
	for(auto length : lengths)
		count_num[length] = 0;
	
	//get the words
	ifstream ifs("../data/letter.txt");
	for(string word; ifs >> word; /* */)
		for(auto IsThisLength : vi)
			if(IsThisLength(word))
				++count_num[IsThisLength.getLength()];
	
	//output
	for(auto a : count_num)
		cout << a.first << " : " << a.second << endl;

	return 0;
}

#endif
