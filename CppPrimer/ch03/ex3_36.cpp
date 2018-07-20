#include <iostream>
#include <iterator>
#include <vector>

using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

bool compare(int * beg1,int * end1,int * beg2,int * end2)
{
	if((end1-beg1)!=(end2-beg2))
	{
		return false;
	}
	else
	{
		for(;beg1!=end1;++beg1,++beg2)
		{
			if(*beg1!=*beg2)
				return false;
		}
	}
	return true;
}

int main()
{
	int array1[5]={1,2,3,4,5},array2[5]={1,2,3,4,5};
	if(compare(begin(array1),end(array1),begin(array2),end(array2)))
		cout<<"two same array is true"<<endl;
	else
		cout<<"two same array is false"<<endl;
	vector<int> vi1={1,2,3},vi2={1,2,3};
	if(vi1==vi2)
		cout<<"two same array is true"<<endl;
	else
		cout<<"two same array is false"<<endl;
	return 0;
}
