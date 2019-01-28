#include "textquery.h"

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

ostream& operator<<(ostream& out, const QueryResult& qr)
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

ostream& print(ostream& out, const QueryResult& qr, size_t front, size_t back)
{
	if(front > back)
	{
		out << "illegal range!!" << endl;
		return out;
	}
	else
	{
		out << qr.word << " occurs " << qr.lines->size() << " "
		<< (qr.lines->size() > 1 ? "times" : "time") << endl;
		for(auto a : *(qr.lines))
		{
			if(a + 1 >= front && a + 1 <= back)
			{
				out << "\t(line" << a + 1 << ")";
		
				auto ptr = qr.file->begin();
				for(; a != 0; a--)
					ptr++;
				out << ptr.deref() << endl;
			}
		}
		return out;

	}
}
