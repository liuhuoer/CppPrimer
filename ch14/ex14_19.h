#ifndef CH14_19_H 
#define CH14_19_H 

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
	Book() = default;
	Book(unsigned isbn, std::string const & name, std::string const & author, 
			std::string const & pubdate, unsigned number)
		:isbn_(isbn), name_(name), author_(author),
		pubdate_(pubdate), number_(number){}

	explicit Book(std::istream & in);

	Book& operator+=(const Book&);

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
