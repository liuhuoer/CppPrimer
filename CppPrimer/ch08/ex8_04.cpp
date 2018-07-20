#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::vector;
using std::string;
using std::istream;
using std::ifstream;
using std::cout;
using std::endl;

//version 1:
//vector<string> read (istream & i)
//{
//	vector<string> vs;
//	string s;
//	while(getline(i,s))
//		vs.push_back(s);	
//	return vs;
//}
//
//int main()
//{
//	ifstream in("test.txt");
//	vector<string> vs=read(in);
//	for(auto i:vs)
//		cout<<i<<endl;
//
//	return 0;
//}

//version 2:
void read(const string & filename,vector<string> & vs)
{
	ifstream f(filename);
	if(f)
	{
		string buf;
		while(getline(f,buf))
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
