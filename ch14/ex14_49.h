#ifndef CH14_49_H 
#define CH14_49_H 

#include <iostream>
#include <string>

class Book
{
	friend std::istream& operator>>(std::istream&, Book&);
	friend std::ostream& operator<<(std::ostream&, const Book&);
	friend bool operator==(const Book&, const Book&);
	friend bool operator!=(const Book&, const Book&);
	friend bool operator<(const Book&, const Book&);
	friend bool operator>(const Book&, const Book&);
	friend Book operator+(const Book&, const Book&);

public:
	//constructors
	Book() = default;
	Book(unsigned isbn, std::string const & name, std::string const & author, 
			std::string const & pubdate, unsigned number)
		:isbn_(isbn), name_(name), author_(author),
		pubdate_(pubdate), number_(number) {}

	Book(const Book& rhs) : isbn_(rhs.isbn_), name_(rhs.name_), author_(rhs.author_),
		pubdate_(rhs.pubdate_), number_(rhs.number_) {}
	Book(Book&& rhs) : isbn_(rhs.isbn_), name_(rhs.name_), author_(rhs.author_),
		pubdate_(rhs.pubdate_), number_(rhs.number_) {}
	
	explicit Book(std::istream & in);
	//operators
	Book& operator=(const Book&);
	Book& operator=(Book&&) noexcept;

	Book& operator+=(const Book&);

	explicit operator bool() const { return isbn_ > 0? true : false;}

private:
	unsigned isbn_;
	std::string name_;
	std::string author_;
	std::string pubdate_;
	unsigned number_;
};

std::istream& operator>>(std::istream&, Book&);
std::ostream& operator<<(std::ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);
bool operator<(const Book&, const Book&);
bool operator>(const Book&, const Book&);
Book operator+(const Book&, const Book&);

#endif
