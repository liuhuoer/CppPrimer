#include <iostream>

using std::cout;
using std::endl;

int main()
{
	cout<<"bool:\t\t\t"<<sizeof(bool)<<" bytes"<<endl;
	//charactor
	cout<<"char:\t\t\t"<<sizeof(char)<<" bytes"<<endl;
	cout<<"wchar_t:\t\t"<<sizeof(wchar_t)<<" bytes"<<endl;
	cout<<"char16_t:\t\t"<<sizeof(char16_t)<<" bytes"<<endl;
	cout<<"char32_t:\t\t"<<sizeof(char32_t)<<" bytes"<<endl;
	//integer
	cout<<"short:\t\t\t"<<sizeof(short)<<" bytes"<<endl;
	cout<<"int:\t\t\t"<<sizeof(int)<<" bytes"<<endl;
	cout<<"long:\t\t\t"<<sizeof(long)<<" bytes"<<endl;
	cout<<"long long:\t\t"<<sizeof(long long)<<" bytes"<<endl;
	//float
	cout<<"float:\t\t\t"<<sizeof(float)<<" bytes"<<endl;
	cout<<"double:\t\t\t"<<sizeof(double)<<" bytes"<<endl;
	cout<<"long double:\t\t"<<sizeof(long double)<<" bytes"<<endl;
	//width integer
	cout<<"int8_t:\t\t\t"<<sizeof(int8_t)<<" bytes"<<endl;
	cout<<"uint8_t:\t\t"<<sizeof(uint8_t)<<" bytes"<<endl;
	cout<<"int16_t:\t\t"<<sizeof(int16_t)<<" bytes"<<endl;
	cout<<"uint16_t:\t\t"<<sizeof(uint16_t)<<" bytes"<<endl;
	cout<<"int32_t:\t\t"<<sizeof(int32_t)<<" bytes"<<endl;
	cout<<"uint32_t:\t\t"<<sizeof(uint32_t)<<" bytes"<<endl;
	cout<<"int64_t:\t\t"<<sizeof(int64_t)<<" bytes"<<endl;
	cout<<"uint64_t:\t\t"<<sizeof(uint64_t)<<" bytes"<<endl;

	return 0;
}
