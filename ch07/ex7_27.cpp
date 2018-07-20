#include"ex7_27.h"
#include<iostream>

using std::cout;

int main()
{
	Screen myscreen(5,5,'X');
	myscreen.move(4,0).set('#').display(cout);
	cout<<"\n";
	myscreen.display(cout);
	cout<<"\n";
	return 0;
}
