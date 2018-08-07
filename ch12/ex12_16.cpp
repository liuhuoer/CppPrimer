#include <iostream>
#include <memory>
#include <string>

using std::unique_ptr;using std::string;

int main()
{
	unique_ptr<string> ui(new string("CppPrimer"));
	//copy constructor(Foo(const Foo &));
	/*error:error use of deleted function "unique_ptr<string>"
	 * */
	//unique_ptr<string> c_ui(ui);
	
	//assign;
	/*error:error use of deleted function "unique_ptr<string>"
	 * */
	//unique_ptr<string> a_ui;
	//a_ui=ui;

	return 0;
}
