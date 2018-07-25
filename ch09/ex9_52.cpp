#include <iostream>
#include <string>
#include <stack>

using std::cout;using std::endl;using std::string;using std::stack;

int main()
{
	string expression="My (C++) primer 5th version";
	stack<char> st;

	int value_num=0;
	for(auto const & i:expression)
	{
		if(i=='(')
		{
			++value_num;
			continue;
		}
		if(i==')')
		{
			--value_num;
			continue;
		}
		if(value_num)
			st.push(i);
			
	}

	string result;
	while(!st.empty())	//error_1:use st.empty() to judge 
	{
		result.insert(result.begin(),st.top());
		st.pop();
	}

	expression.replace(expression.find("("),result.size()+2,result);
	cout<<expression<<endl;

	return 0;
}
