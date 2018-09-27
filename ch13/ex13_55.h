#ifndef ex12_55_h
#define ex12_55_h

#include <iostream> 
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>

using std::cout;using std::endl;using std::vector;using std::string;using std::weak_ptr;using std::shared_ptr;using std::size_t;using std::initializer_list;using std::out_of_range;

class StrBlobPtr;
/*StrBlob
 * */
class StrBlob 
{
public:
	friend class StrBlobPtr;
	StrBlobPtr begin();
	StrBlobPtr end();
//	StrBlobPtr begin(){return StrBlobPtr(*this);}
//	StrBlobPtr end(){return StrBlobPtr(*this,data->size());}

	using size_type=vector<string>::size_type;
	StrBlob():data(std::make_shared<vector<string>>()){}
	StrBlob(initializer_list<string> ils):data(std::make_shared<vector<string>>(ils)){}
	//information about size;
	size_type size()const{return data->size();}
	bool empty()const{return data->empty();}
	//insert or delete element;
	void push_back(const string & s){data->push_back(s);}
	void push_back(string&& s){data->push_back(std::move(s));}
	void pop_back();
	//get element;
	string & front();
	string & back();
private:
	std::shared_ptr<vector<string>> data;
	void check(size_type i,const string & msg)const;
};

/*StrBlobPtr
 * */
class StrBlobPtr
{
public:
	StrBlobPtr():curr(0){}
	StrBlobPtr(StrBlob &a,size_t curr_=0):
		wpvs(a.data),curr(curr_){}
	string& deref()const;//deref*;
	StrBlobPtr& incr();//increase++;
	bool operator !=(const StrBlobPtr & ptr){return curr!=ptr.curr;}
private:
	shared_ptr<vector<string>> check(size_t,const string &)const;
	weak_ptr<vector<string>> wpvs;
	size_t curr;
};

#endif
