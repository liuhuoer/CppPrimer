#include <iostream>
#include <string>

using std::cout;using std::endl;using std::string;

int main()
{
	string number="0123456789",s="ab2c3d7R4E6";
	string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };

	string::size_type curr=0;
	while((curr=s.find_first_not_of(alphabet,curr))!=string::npos)
	{
		cout<<"The number "<<s[curr]<<" is at index: "<<curr<<endl;
		++curr;
	}

	curr =0;
	while((curr=s.find_first_not_of(number,curr))!=string::npos)
	{
		cout<<"The alphabet "<<s[curr]<<" is at index: "<<curr<<endl;
		++curr;
	}

	return 0;
}
