#include "ex12_27.h"

using std::cin;

auto runQueries(ifstream & ifs)
{
	TextQuery tq(ifs);
	while(true)
	{
		string s;
		//rewrite_:change error(!cin>>s)
		if(!(cin>>s)||s=="!q")
			break;
		//check s is include text;
		if(!tq.query(s))
		{
			cout<<"not find!!"<<endl;
			continue;
		}
		QueryResult result(tq.query(s));
		result.print(cout)<<endl;
	}
	return 0;
}

int main()
{
	ifstream ifs("../data/text_query.txt");
	runQueries(ifs);

	return 0;
}
