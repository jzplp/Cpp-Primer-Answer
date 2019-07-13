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

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
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


void Message::addFolder(Folder *f)
{
	folders.insert(f);
}

void Message::remFolder(Folder *f)
{
	folders.erase(f);
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

std::ostream & Message::print(std::ostream & os) const
{
	os << contents << " " << folders.size();
	return os; 
}

void Folder::addMsg(Message *m)
{
	messages.insert(m);
}

void Folder::remMsg(Message *m)
{
	messages.erase(m);
}

void Folder::add_to_Messages(const Folder &f)
{
	for(Message * m : f.messages)
		m->addFolder(this);
}

Folder::Folder(const Folder &f) : messages(f.messages)
{
	add_to_Messages(f);
}

void Folder::remove_from_Messages()
{
	for(Message * m : messages)
		m->remFolder(this);
}

Folder::~Folder()
{
	remove_from_Messages();
}

Folder & Folder::operator=(const Folder &f)
{
	remove_from_Messages();
	messages = f.messages;
	add_to_Messages(f);
	return *this;
}

void Folder::show(std::ostream & os)
{
	os << "Folder:" << std::endl;
	for(Message * m : messages)
		m->print(os) << std::endl; 
}
