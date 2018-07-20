#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::vector;
using std::string;
using std::istream;
using std::ifstream;
using std::cin;
using std::cout;
using std::endl;

void read(const string & filename,vector<string> & vs)
{
	ifstream f(filename);
	if(f)
	{
		string buf;
		while(f>>buf)
			vs.push_back(buf);
	}
}

int main()
{
	vector<string> vs;
	read("./test.txt",vs);
	for(const auto & i:vs)
		cout<<i<<endl;
	return 0;
}
