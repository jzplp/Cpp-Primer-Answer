#include<set>
#include<string>
#include<iostream>
#include "Message.h"

void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
	for(Folder * f : m.folders)
		f->addMsg(this);
}

Message::Message(const Message &m) : contents(m.constents), folders(m.folders)
{
	add_to_Folders(m); 
}

void Message::remove_from_Folders()
{
	for(Folder * f : folders)
		f->remMsg(this);
}

Message::~Message()
{
	remove_from_Folders();
}

Message & Message::operator=(const Message &rhs)
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

void swap(Message &lhs, Message &rhs)
{
	using std::swap;
	for(Folder *f : lhs.folders)
		f->remMsg(&lhs);
	for(Folder *f : rhs.folders)
		f->remMsg(&rhs);
		
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	
	for(Folder *f : lhs.folders)
		f->addMsg(&lhs);
	for(Folder *f : rhs.folders)
		f->addMsg(&rhs);
}

std::ostream & Message::print(std::ostream & os)
{
	os << contents << " " << folders.size();
	return os; 
}
