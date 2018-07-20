#include <iostream>

using std::cout;
using std::endl;
using std::begin;
using std::end;

void print(const int &x)
{
	cout<<"1th"<<x<<endl;
}

void print(const char *x)
{
	if(x)
	{
		cout<<"2th";
		while(*x)
			cout<<*x++;
		cout<<endl;
	}
}

void print(const int * beg,const int * end)
{
	cout<<"3th";
	while(beg!=end)
		cout<<*beg++;
	cout<<endl;
}

void print(const int ia[],size_t size)
{
	cout<<"4th";
	for(size_t i=0;i!=size;++i)
		cout<<ia[i];
	cout<<endl;
}

void print(const int (&a)[2])
{
	cout<<"5th";
	for(auto x:a)
		cout<<x;
	cout<<endl;
}

int main()
{
	int i=0,j[2]={0,1};

	print(i);//1th
	//2th version is char[],it cann't be used int[].
	print(begin(j),end(j));//3th
	print(j,end(j)-begin(j));//4th
	print(j);
	return 0;
}
