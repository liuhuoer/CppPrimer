#include "ex13_31.h"
#include <algorithm>
int main()
{
	//input;
	HasPtr a("c"),b("b"),c("a");
	vector<HasPtr> vh{a,b,c};
	//vector<HasPtr> vh;
	//for(string s;std::cin>>s;)
	//	vh.emplace_back(s);

	//sort;
	std::sort(vh.begin(),vh.end());

	//output;
	for(auto a:vh)
		a.output();

	return 0;
}
