#include <iostream>
#include <string>
#include <vector>

using std::cout;using std::endl;using std::string;using std::vector;

class mydate
{
public:
	mydate(const string & s);
	void print();
private:
	unsigned year,month,day;
};

mydate::mydate(const string & s)
{	
	vector<string> vs;
	string::size_type curr;
	string::size_type prev=0;
	if((curr=s.find_first_of("/"))!=string::npos)
	{
		for(;(curr=s.find_first_of("/",curr))!=string::npos;prev=++curr)
		{
			vs.push_back(s.substr(prev,curr));
		}
		year=stoi(s.substr(prev,s.size()));
		month=stoi(vs[1]);
		day=stoi(vs[0]);//
	}
	else if((curr=s.find_first_of(" ,"))!=string::npos)
	{
		prev=0;
		for(;(curr=s.find_first_of(" ,",curr))!=string::npos;prev=++curr)	
		{
			//cout<<"test"<<curr;
			vs.push_back(s.substr(prev,curr));
			//cout<<"XXX"<<vs[0];
		}
		year=stoi(s.substr(prev,s.size()));
		//month is vs[0]
		day=stoi(vs[1]);
		if(vs[0].find("Jan")!=string::npos)month=1;
		else if(vs[0].find("Feb")!=string::npos)month=2;
		else if(vs[0].find("Mar")!=string::npos)month=3;
		else if(vs[0].find("Apr")!=string::npos)month=4;
		else if(vs[0].find("May")!=string::npos)month=5;
		else if(vs[0].find("Jun")!=string::npos)month=6;
		else if(vs[0].find("Jul")!=string::npos)month=7;
		else if(vs[0].find("Aug")!=string::npos)month=8;
		else if(vs[0].find("Sep")!=string::npos)month=9;
		else if(vs[0].find("Oct")!=string::npos)month=10;
		else if(vs[0].find("Nov")!=string::npos)month=11;
		else if(vs[0].find("Dec")!=string::npos)month=12;
	}

}

void mydate::print()
{
	cout<<"year="<<year<<"\nmonth="<<month<<"\nday="<<day<<endl;
}

int main()
{
	mydate d1("25/12/2018"),d2("Mar 21,1994");
	d1.print();
	cout<<endl;
	d2.print();
	return 0;
}
