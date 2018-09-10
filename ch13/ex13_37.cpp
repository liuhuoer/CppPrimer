#include "ex13_37.h"
/*
 * class Message
 * */
void swap(Message &lhm, Message &rhm)
{
	using std::swap;
	lhm.remove_from_Folders();
	rhm.remove_from_Folders();

	swap(lhm.content,rhm.content);
	swap(lhm.folders,rhm.folders);

	lhm.add_to_Folders(lhm);
	rhm.add_to_Folders(rhm);
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

Message::~Message()
{
	remove_from_Folders();
}

void Message::save(Folder & f)
{
	addFld(&f);
	f.addMsg(this);
}

void Message::remove(Folder & f)
{
	remFld(&f);
	f.remMsg(this);
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

/*
 *class Folder
 * */
void swap(Folder &lhf, Folder &rhf)
{
	using std::swap;
	lhf.remove_from_Message();
	rhf.remove_from_Message();

	swap(lhf.msgs,rhf.msgs);

	lhf.add_to_Message(lhf);
	rhf.add_to_Message(rhf);
}

Folder::Folder(const Folder & f):msgs(f.msgs)
{
	add_to_Message(f);
}

Folder::~Folder()
{
	remove_from_Message();
}

Folder & Folder::operator=(const Folder & f)
{
	remove_from_Message();
	msgs=f.msgs;
	add_to_Message(f);
	return *this;
}

void Folder::add_to_Message(const Folder & f)
{
	for(auto a:f.msgs)
		a->save(*this);
}

void Folder::remove_from_Message()
{
	for(auto a:msgs)
		a->remove(*this);
}

int main()
{
	return 0;
}
