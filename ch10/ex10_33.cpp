#include <fstream>
#include <iterator>
#include <algorithm>

using std::ifstream;using std::ofstream;using std::istream_iterator;using std::ostream_iterator;

//int main()
//{
//	//init ifstream and ofstream;
//	ifstream ifs("../data/int.txt");
//	ofstream ofs_odd("../data/int_odd.txt"),ofs_even("../data/int_even.txt");
//	//init istream_iterator and ostream_iterator;
//	istream_iterator<int> is_iter(ifs),eof;
//	ostream_iterator<int> os_iter_odd(ofs_odd," "),os_iter_even(ofs_even,"\n");
//	//deal with odd and even;
//	while(is_iter!=eof)
//	{
//		if(*is_iter&0x1)
//			*os_iter_odd++=*is_iter++;
//		else
//			*os_iter_even++=*is_iter++;
//	}
//	return 0;
//}

//rewrite
int main(int argc,char * argv[])
{
	//init ifstream and ofstream;
	if(argc!=4)
		return -1;
	ifstream ifs(argv[1]);
	ofstream ofs_odd(argv[2]),ofs_even(argv[3]);
	//init istream_iterator and ostream_oterator;
	istream_iterator<int> is_iter(ifs),eof;
	ostream_iterator<int> os_iter_odd(ofs_odd," "),os_iter_even(ofs_even,"\n");
	//deal with odd and even;
	for_each(is_iter,eof,[&os_iter_odd,&os_iter_even](const int i){*(i&0x1?os_iter_odd:os_iter_even)++=i;});

	return 0;
}
