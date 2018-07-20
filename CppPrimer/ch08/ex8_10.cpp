#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

using std::ifstream;
using std::istringstream;
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main(int argc,char * argv[])
{
	string line,word;
	ifstream input(argv[1]);
	//ofstream output(argv[2],ofstream::app);
	vector<string> vs;

	while(getline(input,line))
		vs.push_back(line);

	for(const auto & i:vs)
	{
		istringstream iss(i);
		while(iss>>word)
			cout<<word<<endl;
	}
	return 0;
}
