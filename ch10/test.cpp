#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using std::cout;using std::endl;using std::accumulate;using std::vector;using std::string;

int main()
{
	vector<string> vs={"I want","you."};
	string sum=accumulate(vs.begin(),vs.end(),string("chocolate,"));
	cout<<sum<<endl;
	return 0;
}
