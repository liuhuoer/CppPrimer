#include <iostream>
#include <string>

using std::cout;using std::endl;using std::string;

void insert_name(string & s,const string & prefix,const string & lastname)
{
	s.insert(0,prefix);
	s.append(lastname);
}

int main()
{
	string s="Bran.";
	insert_name(s,"Mr.","Stark");
	cout<<s<<endl;

	return 0;
}
