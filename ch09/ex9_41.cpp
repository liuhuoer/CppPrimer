#include <iostream>
#include <vector>
#include <string>

using std::cout;using std::endl;using std::vector;using std::string;

int main()
{
	vector<char> vc={'h','e','l','l','o',',','w','o','r','l','d','!'};
	char *p=&vc[0];
	string s1(p);
	//string s2(vc,6);		//error_1
	//string s3(vc,6,6);		//error_2
	//string s4=vc.substr(6,6);	//error_3
	string s5(vc.begin(),vc.end());
	cout<<"s1="<<s1<<"s5="<<s5<<endl;
	return 0; 
}
