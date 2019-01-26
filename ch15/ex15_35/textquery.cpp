#include "textquery.h"
#include "queryresult.h"

//@ybug@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
TextQuery::TextQuery(ifstream& ifs) : file(new StrBlob)//rewrite_:init file with new;
{
	for(string line; getline(ifs, line); )
	{
		file->push_back(line);
		auto n = file->size() - 1;
		istringstream is(line);
		for(string word; is >> word; )
		{
			auto & curr = wm[word];
			if(!curr)
				//rewrite_:using reset(new set);
				curr.reset(new set<line_no>);
			curr->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string & word) const
{
	auto p = wm.find(word);
	static shared_ptr<set<line_no>> no_find(new set<line_no>);
	if(p == wm.end())
		return QueryResult(word, no_find, file);
	else
		return QueryResult(word, p->second, file);
}
/*
ostream& print(ostream& out, const QueryResult& qr)
{
	out << qr.word << " occurs " << qr.lines->size() << " "
		<< (qr.lines->size() > 1 ? "times" : "time") << endl;
	for(auto a : *(qr.lines))
	{
		out << "\t(line" << a + 1 << ")";

		auto ptr = qr.file->begin();
		for(; a != 0; a--)
			ptr++;
		out << ptr.deref() << endl;
	}

	return out;
}
*/

/*
void runQueries(ifstream & ifs)
{
	TextQuery tq(ifs);
	while(true)
	{
		cout<<"enter word to look for,or !q to quit: "<<endl;
		string s;
		//rewrite_:change error(!cin>>s)
		if(!(cin >> s)||s == "!q")
			break;
		print(cout, tq.query(s)) << endl;
	}
}

int main()
{
	ifstream ifs("../data/text_query.txt");
	runQueries(ifs);

	return 0;
}

*/

