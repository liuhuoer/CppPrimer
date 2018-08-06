#include <iostream>
#include <vector> 
#include <memory>

using std::cin;using std::cout;using std::endl;using std::vector;using Spvi=std::shared_ptr<vector<int>>;

auto getVector()->Spvi
{
	//rewrite_:replace new XX() with make_shared<XX>();
	Spvi p_vi=std::make_shared<vector<int>>();
	for(int i=0;cin>>i;)
		p_vi->push_back(i);

	return p_vi;
}

auto printVi(Spvi p_vi)->std::ostream &
{
	for(auto a:*p_vi)
		cout<<a<<endl;
	return cout;
}

int main()
{
	//get Spvi;
	auto p_vi=getVector();
	//print *Spvi;
	printVi(p_vi)<<endl;

	return 0;
}
