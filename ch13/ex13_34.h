#include <string>
#include <set>

using std::string;using std::set;

class Message
{
	friend class Folder;
	friend swap(Message &,Message &);
public:
	explicit Message(const string & s=""):content(s){}
	Message(const Message & m);
	Message & operator =(const Message &);
	~Message();
	//(Message->folder)save to one folder; or remove;
	void save(Folder &);
	void remove(Folder &);
private:
	string content;
	set<Folder *> folders;
	//change pointer in Folder(Folder->Message);
	void add_to_Folders(const Message &);
	void remove_from_Folders();
};
