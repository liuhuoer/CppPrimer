#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>

using std::cout;using std::endl;using std::vector;using std::list;using std::map;using std::string;

int main()
{
	//ex11_9
	map<string,list<size_t>> ms;	//rewrite_:change int to size_t;
	//ex11_10
	map<vector<int>::iterator,int> mv;
	map<list<int>::iterator,int> ml;
	vector<int> vi;
	list<int> li;

	mv.insert(std::pair<vector<int>::iterator,int>(vi.begin(),0));
	//error_:no match for 'operator<'; because list<int>::iterator is bidirectional iterator(no "<"), and vector's iterator is random-access iterator(support "<"); 
	//ml.insert(std::pair<list<int>::iterator,int>(li.begin(),0));

	return 0;
}
