#include "ex12_19.h"
#include <fstream>
#include <sstream>

using std::ifstream;using std::istringstream;using std::getline;

int main()
{
	StrBlob str;
	ifstream ifs("../data/unique.txt");
	for(string line;getline(ifs,line);)
	{
		istringstream ss(line);
		for(string word;ss>>word;)
			str.push_back(word);
	}

	for(StrBlobPtr b_ptr(str.begin()),e_ptr(str.end());b_ptr!=e_ptr;b_ptr.incr())
		cout<<b_ptr.deref()<<endl;

	return 0;
}
