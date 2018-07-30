#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>

using std::cout;using std::endl;using std::vector;using std::string;using std::ifstream;using std::istream_iterator;using std::ostream_iterator;

int main()
{
	ifstream ifs("../data/unique.txt");
	if(!ifs)
		return -1;
	istream_iterator<string> item_iter(ifs),eof;
	vector<string> vs;

	//copy from stream to vs;
	copy(item_iter,eof,back_inserter(vs));
	//print;
	copy(vs.begin(),vs.end(),ostream_iterator<string>(cout,"\n"));

	return 0;
}
