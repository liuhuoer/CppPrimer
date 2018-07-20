#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;
using int_array=int[4];

int main()
{
	int ai[3][4]={0,1,2,3,4,5,6,7,8,9,10,11};
	cout<<"The first version:"<<endl;
	for(auto & row:ai)
		for(auto col:row)
			cout<<col<<" ";
		cout<<endl;
	cout<<"The second version:"<<endl;
	for(size_t i=0;i!=3;i++)
		for(size_t j=0;j!=4;j++)
			cout<<ai[i][j]<<" ";
		cout<<endl;
	cout<<"The third version:"<<endl;
	for(auto row=begin(ai);row!=end(ai);++row)
		for(auto *col=begin(*row);col!=end(*row);++col)
			cout<<*col<<" ";
		cout<<endl;
	return 0;
}
