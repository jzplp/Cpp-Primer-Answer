#ifndef MESSAGE_H
#define MESSAGE_H

#include<string>
#include<set>
#include<iostream>

class Folder;

class Message
{
	friend class Folder;
	friend void swap(Message &lhs, Message &rhs);
public:
	
	explicit Message(const std::string &str = "") : contents(str) { }
	Message(const Message &);
	Message & operator=(const Message &);
	~Message();
	
	Message(Message &&m);
	Message & operator=(Message && rhs);
	
	void save(Folder &);
	void remove(Folder &);
	
	std::ostream & print(std::ostream & os) const;
	
private:
	void addFolder(Folder *);
	void remFolder(Folder *);
	std::string contents;
	std::set<Folder *> folders;
	
	void add_to_Folders(const Message &);
	void remove_from_Folders();
	void move_Folders(Message * m);
};

class Folder
{
	friend class Message; 
	friend void swap(Message &lhs, Message &rhs);
	
public:
	
	Folder() = default;
	Folder(const Folder &);
	Folder & operator=(const Folder &f); 
	~Folder();
	
	Folder(Folder &&f);
	Folder & operator=(Folder && rhs);
	
	void show(std::ostream & os);
	
private:
	
	void addMsg(Message *m);
	void remMsg(Message *m);
	void move_Messages(Folder * f);
	
	void add_to_Messages(const Folder &);
	void remove_from_Messages();
	std::set<Message *> messages;
	
};

#endif
