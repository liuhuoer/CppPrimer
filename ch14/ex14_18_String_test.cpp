#include "ex14_16_String.cpp"

int main()
{
	char c[] = "hello";

	String s1(c);
	cout << "s1 : " << s1 << endl;

	String s0;

	String s2 = "helloworld";
	cout << "s2 : " << s2 << endl;

	String s3;
	cin >> s3;
	cout << "s3 : " << s3 << endl;

	if(s2 == s3)
		cout<<"s2 == s3"<<endl;

	return 0;
}
