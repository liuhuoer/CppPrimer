#include <iostream>
#include <list>
#include <string>
#include <fstream>

using std::cout;using std::endl;using std::list;using std::string;using std::ifstream;

void myprint(const string & s,list<string> & ls)
{
	cout<<s<<"(size="<<ls.size()<<")"<<endl;
	for(auto a:ls)
		cout<<a<<" ";
	cout<<endl;
	//cout<<ls.back()<<endl;
}

void elimDups(list<string> & ls)
{
	myprint("original: ",ls);
	ls.sort();
	myprint("sort: ",ls);
	ls.unique();
	myprint("unique: ",ls);
}

int main()
{
	ifstream ifs("../data/unique.txt");
	list<string> ls;
	string s;

	if(!ifs)
		return -1;
	while(ifs>>s)
		ls.push_back(s);
	elimDups(ls);

	return 0;
}
