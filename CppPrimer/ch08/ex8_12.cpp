#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using std::cin;using std::cout;using std::endl;using std::istringstream;using std::vector;using std::string;using std::ifstream;

struct PersonInfo
{
	string name;
	vector<string> phones;
};

int main(int argc,char * argv[])
{
	string line,word;
	ifstream input(argv[1]);
	vector<PersonInfo> people;
	istringstream record;
	while(getline(input,line))
	{
		PersonInfo info;
		record.clear();
		record.str(line);
		record>>info.name;
		while(record>>word)
			info.phones.push_back(word);
		people.push_back(info);
	}

	for(const auto & i:people)
	{
		cout<<i.name<<" ";
		for(auto & s:i.phones)
			cout<<s<<"";
		cout<<endl;
	}

	return 0;
}

