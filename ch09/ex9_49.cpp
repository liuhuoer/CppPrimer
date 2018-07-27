#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::cout;using std::endl;using std::string;using std::vector;using std::ifstream;

int main()
{
	ifstream ifs("../data/letter.txt");	//review_1:ifstream	
	if(!ifs)
		return -1;		//rewrite_1:judge the file

	vector<string> vs;
	int max_long=0;
	for(string word;ifs>>word;)	//review_2:ifs>>word
	{
		if(word.find_first_of("aceimnorsuvwxz")==string::npos&&max_long<=word.size())
		{
			vs.push_back(word);
			max_long=word.size();//
		}
	}
	for(auto i:vs)
		if(i.size()>=max_long)
			cout<<i<<endl;
	return 0;
}
