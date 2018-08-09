#include <iostream>
#include <memory>
#include <string>

using std::cin;using std::cout;using std::endl;using std::allocator;using std::string;

int main()
{
	allocator<string> as;
	//allocate memory;
	auto p_as=as.allocate(6);
	auto curr=p_as;
	for(string s;cin>>s&&curr!=p_as+6;)
		as.construct(curr++,s);
	for(auto a=p_as;a!=curr;++a)
		cout<<*a<<" ";
	cout<<endl;
	//calculate size;
	std::size_t size_as=curr-p_as;
	cout<<"size_t="<<size_as<<endl;
	//release memory;
	as.destroy(p_as);
	as.deallocate(p_as,6);

	return 0;
}
