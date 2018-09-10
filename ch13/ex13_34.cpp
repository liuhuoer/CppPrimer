#include "ex13_34.h"

void swap(Message &lhm,Message &rhm)
{
	using std::swap;
	rhm.remove_from_Folder();
	rhm.remove_from_Folder();
	swap(lhm.content,rhm.content);
	swap(lhm.folders,rhm.folders);
	rhm.add_to_Folders(rhm);
	lhm.add_to_Folders(lhm);
}

Message::~Message()
{
	remove_from_Folders();
}

Message::Message(const Message & m):content(m.content),folders(m.folders)
{
	add_to_Folders(m);
}

Message& Message:: operator=(const Message & rm)
{
	remove_from_Folders();
	content=rm.content;
	folders=rm.folders;
	add_to_Folders(rm);
	return *this;
}

void Message::add_to_Folders(const Message & m)
{	//using m.folders but folders(other Messages can use this function)
	for(auto a:m.folders)
		a->addMsg(this);
}

void Message::remove_from_Folders()
{
	for(auto a:folders)
		a->remMsg(this);
}

void Message::save(Folder & f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder & f)
{
	folders.erase(&f);
	f.remMsg(this);
}

int main()
{
	return 0;
}
