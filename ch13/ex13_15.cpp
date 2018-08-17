
#include <iostream>

using std::cout;using std::endl;

class numbered
{
public:
	numbered(){mysn=++count;}
	numbered(const numbered &){mysn=++count;}

	int mysn;
	static int count;	//rewrite_:init must out of class;
};

int numbered::count=6;

void f(numbered s)
{
	cout<<s.mysn<<endl;
}

int main()
{
	numbered a,b=a,c=b;
	f(a);
	f(b);
	f(c);

	return 0;
} 
