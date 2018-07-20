#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using std::cin;using std::cout;using std::endl;using std::istringstream;using std::vector;using std::string;

struct PersonInfo
{
	string name;
	vector<string> phones;
};

int main()
{
	string line,word;
	vector<PersonInfo> people;
	istringstream record;
	while(getline(cin,line))
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

