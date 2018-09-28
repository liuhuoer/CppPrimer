#ifndef ex14_5_h
#define ex14_5_h

#include <iostream>
#include <string>
using std::istream;using std::ostream;
class Book
{
	friend istream& operator>>(istream&, Book&);
	friend ostream& operator<<(ostream&, const Book&);
	friend bool operator==(const Book&, const Book&);
	friend bool operator!=(const Book&, const Book&);
	
public:
	Book(unsigned isbn,std::string const & name,std::string const & author,std::string const & pubdate)
		:isbn_(isbn),name_(name),author_(author),pubdate_(pubdate)
	{}

	explicit Book(std::istream & in)
	{
		in>>isbn_>>name_>>author_>>pubdate_;
	}
private:
	unsigned isbn_;
	std::string name_;
	std::string author_;
	std::string pubdate_;
};

istream& operator>>(istream&, Book&);
ostream& operator<<(ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);

#endif
