#ifndef ex13_37_h
#define ex13_37_h

#include <string>
#include <set>

using std::string;using std::set;

class Folder;

class Message
{
	friend class Folder;
	friend void swap(Message &,Message &);
public:
	explicit Message(const string & s=""):content(s){}
	Message(const Message &);
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

	void addFld(Folder * f){folders.insert(f);}
	void remFld(Folder * f){folders.erase(f);}
};

void swap(Message &,Message &);

class Folder
{
	friend class Message;
	friend void swap(Folder &,Folder &);
public:
	Folder()=default;
	Folder(const Folder &);
	Folder& operator=(const Folder &);
	~Folder();
	void addMsg(Message *m){msgs.insert(m);}
	void remMsg(Message *m){msgs.erase(m);}
private:
	set<Message *> msgs;
	void add_to_Message(const Folder &);
	void remove_from_Message();
};

void swap(Folder &,Folder &);

#endif
