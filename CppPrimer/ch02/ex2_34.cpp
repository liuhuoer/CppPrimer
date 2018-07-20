#include <iostream>

int main()
{
	int i=0,&r=i;
	auto a=r;
	const int ci=i,&cr=ci;
	auto b=ci;
	auto c=cr;
	auto d=&i;
	auto e=&ci;
	const auto f=ci;
	auto &g=ci;

	a=42;//a is int
	b=42;//b is int
	c=42;//c is int
	*d=42;//d is int *
	//e=42;//e is int * which points to const,it cann't be fixed
	//f=42;//f is const int,it cann't be fixed
	//g is const int &

	return 0;
}
