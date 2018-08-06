#include <iostream>
#include <memory>

using std::cout;using std::endl;using Spi=std::shared_ptr<int>;

auto process(Spi s)
{
	cout<<"process():"<<s.use_count()<<endl;
}

int main()
{
	auto p=new int();
	auto sp=std::make_shared<int>();
	/*legal.copy sp to parament s.
	 */
	//process(sp);
	/*illegal. plain pointer can't convert to smart pointer.
	 */
	//process(new int());
	
	/*illeagal.plain pointer can't convert to smart pointer.
	 */
	//process(p);
	
	/*leagal,but will make p lose efficacy.
	 */
	//process(Spi(p));



	return 0;
}
