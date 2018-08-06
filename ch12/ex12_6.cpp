#include <iostream>
#include <vector> 

using std::cin;using std::cout;using std::endl;using std::vector;using Pvi=vector<int>*;
//rewrite_:define Pvi replace vector<int>*;

auto getVector()->Pvi
{
	Pvi p_vi=new vector<int>();
	for(int i=0;cin>>i;)
		p_vi->push_back(i);

	return p_vi;
}

auto printVi(Pvi p_vi)->std::ostream &
//rewrite_:add ->ostream&;
{
	for(auto a:*p_vi)
		cout<<a<<endl;
	return cout;
	//rewrite_:directly return cout;
}

int main()
{
	//get Pvi;
	auto p_vi=getVector();
	//print *Pvi;
	printVi(p_vi)<<endl;
	//delete Pvi;
	delete p_vi;

	return 0;
}
