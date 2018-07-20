#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string str,lastStr;
	getline(cin,str);
	for(auto &c:str)
		if(!ispunct(c))
			lastStr+=c;
	cout<<lastStr<<endl;
	return 0;
}
