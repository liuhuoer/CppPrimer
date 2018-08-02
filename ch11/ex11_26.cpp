#include <iostream>
#include <map>
#include <typeinfo>
#include <string>

using std::cout;using std::endl;using std::map;using std::string;

int main()
{
	map<string,int> ms{{"good",11},{"bad",20}};
	using key_ms=map<string,int>::key_type;

	cout<<"the type of key: "<<typeid(key_ms).name()<<endl;
	cout<<"the type of element: "<<typeid(decltype(ms["good"])).name()<<endl;

	return 0;
}
