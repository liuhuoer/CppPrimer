#include <iostream>

struct Foo
{
	/*nothing*/
};

int main()
{
	return 0;
}

/*
 * 
ex2_39.cpp:3: error: new types may not be defined in a return type
ex2_39.cpp:3: note: (perhaps a semicolon is missing after the definition of 'Foo              ')
ex2_39.cpp:8: error: two or more data types in declaration of 'main'
 * */
