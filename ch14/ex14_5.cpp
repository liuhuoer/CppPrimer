#include "ex14_5.h"

istream& operator>>(istream& is, Book& rhs)
{
	is>>rhs.isbn_>>rhs.name_>>rhs.author_>>rhs.pubdate_;
	return is;
}

ostream& operator<<(ostream& os, const Book& rhs)
{
	os<<rhs.isbn_<<rhs.name_<<rhs.author_<<rhs.pubdate_;
	return os;
}

bool operator==(const Book& lhs, const Book& rhs)
{
	return lhs.isbn_==rhs.isbn_;
}

bool operator!=(const Book& lhs, const Book& rhs)
{
	return lhs.isbn_!=rhs.isbn_;
}

int main()
{
	return 0;
}
