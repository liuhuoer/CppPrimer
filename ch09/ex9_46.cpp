#include <iostream>
#include <string>

using std::cout;using std::endl;using std::string;

void insert_name(string & s,const string & prefix,const string & lastname)
{
	s.insert(s.begin(),prefix.begin(),prefix.end());
	s.insert(s.size(),lastname);
}

int main()
{
	string s="Bran.";
	insert_name(s,"Mr.","Stark");
	cout<<s<<endl;

	return 0;
}
