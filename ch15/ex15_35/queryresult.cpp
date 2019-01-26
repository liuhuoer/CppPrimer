#include "queryresult.h"

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


