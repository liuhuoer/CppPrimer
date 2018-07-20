#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

int main(int argc,char **argv)
{
	string s;
	//Test char*[] and int*[] about cout<<
	//const char * test[]={"ai","b"};
	//cout<<test[0]<<endl;//char* "<<" is different from int* "<<"
	
	//1th version is an error
	//strcpy(s,*argv[1]);//*argv[] is const char*,so it cann't be used here
	//strcat(s," ");
	//strcat(s,argv[2]);
	
	//2th version
	for(int i=1;i!=argc;++i)
		s+=string(argv[i])+" ";
	cout<<s<<endl;
	return 0;
}
