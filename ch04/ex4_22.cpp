#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int grade=74;
	cout<<"The first version "<<((grade<75)?(grade<60)?"fail":"low pass":(grade<90)?"pass":"high pass")<<endl;
	cout<<"The second version ";
	if(grade<60)
		cout<<"fail";
	else if(grade<75)
		cout<<"low pass";
	else if(grade<90)
		cout<<"pass";
	else
		cout<<"high pass";
	cout<<endl;
	return 0;
}
