#include <iostream>
#include <vector>
#include <string>

using std::cout;using std::endl;using std::string;using std::vector;

int  sum_int(const vector<string> & vs)
{
	int sum=0;
	for(auto i:vs)
		sum+=stoi(i);
	return sum;
}

double  sum_double(const vector<string> & vs)
{
	double sum=0.0;
	for(auto i:vs)
		sum+=stod(i);
	return sum;
}

int main()
{
	vector<string> vs={"23","66","88","2.2"};
	cout<<sum_int(vs)<<endl;
	cout<<sum_double(vs)<<endl;
	return 0; 
}
