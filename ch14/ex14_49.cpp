#include "ex14_49.h"

Book::Book(std::istream & in)
{
	in >> isbn_ >> name_ >> author_ >> pubdate_ >> number_;
}

std::istream& operator>>(std::istream& is, Book& book)
{
	is >> book.isbn_ >> book.name_ >> book.author_ >> book.pubdate_ >> book.number_;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
	os << book.isbn_ << " " << book.name_ << " " << book.author_ << " " << book.pubdate_ << " " << book.number_;
	return os;
}

bool operator==(const Book& lhs, const Book& rhs)
{
	return lhs.isbn_ == rhs.isbn_;
}

bool operator!=(const Book& lhs, const Book& rhs)
{
	return lhs.isbn_ != rhs.isbn_;
}

bool operator<(const Book& lhs, const Book& rhs)
{
	return lhs.isbn_ < rhs.isbn_;
}

bool operator>(const Book& lhs, const Book& rhs)
{
	return rhs < lhs;
}

Book operator+(const Book& lhs, const Book& rhs)
{
	Book sum = lhs;
	sum += rhs;
	return sum;
}

Book& Book::operator+=(const Book& rhs)
{
	if(this->isbn_ == rhs.isbn_)
		this->number_ += rhs.number_;
	return *this;
}

Book& Book::operator=(const Book& rhs)
{
	isbn_ = rhs.isbn_;
	name_ = rhs.name_;
	author_ = rhs.author_;
	pubdate_ = rhs.pubdate_;
	number_ = rhs.number_;

	return *this;
}

Book& Book::operator=(Book&& rhs) noexcept
{
	if(this != &rhs)
	{
		isbn_ = rhs.isbn_;
		name_ = rhs.name_;
		author_ = rhs.author_;
		pubdate_ = rhs.pubdate_;
		number_ = rhs.number_;
	
	}
	return *this;
}

