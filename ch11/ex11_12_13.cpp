#include <iostream>
#include <vector>
#include <string>
#include <utility>

using std::cin;using std::cout;using std::endl;using std::vector;using std::string;using std::pair;

int main()
{
	vector<pair<string,int>> vp;
	int i=0;
	for(string s;cin>>s>>i&&s!="!q";)
		vp.push_back({s,i});	//easiliest way; no different with other dypes;
		//vp.push_back(make_pair(s,i));
		//vp.push_back(pair<string,int>(s,i));
		//vp.emplace_back(s,i);

	for(const auto & a:vp)
		cout<<"string:"<<a.first<<"\nint:"<<a.second<<endl;
	
	return 0;
}
