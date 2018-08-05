#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>

using std::cout;using std::endl;using std::string;using std::vector;using std::initializer_list;using std::out_of_range;

class StrBlob 
{
public:
	using size_type=vector<string>::size_type;
	StrBlob():data(std::make_shared<vector<string>>()){}
	StrBlob(initializer_list<string> ils):data(std::make_shared<vector<string>>(ils)){}
	//information about size;
	size_type size()const{return data->size();}
	bool empty()const{return data->empty();}
	//insert or delete element;
	void push_back(const string & s){data->push_back(s);}
	void pop_back();
	//get element;
	string & front();
	string & back();
private:
	std::shared_ptr<vector<string>> data;
	void check(size_type i,const string & msg)const;
};

void StrBlob::pop_back()
{
	check(0,"pop_back on empty StrBlob");
	data->pop_back();
}

string & StrBlob::front()
{
	check(0,"front on empty StrBlob");
	return data->front();
}

string & StrBlob::back()
{
	check(0,"back on empty StrBlob");
	return data->back();
}

void StrBlob::check(size_type i,const string & msg)const
{
	if(i>=data->size())
		throw out_of_range(msg);
}
