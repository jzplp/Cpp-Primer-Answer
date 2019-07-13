#include<iostream> 
#include "Message.h"

int main()
{
	Folder f1;
	Message m1("qwerty");
	m1.save(f1);
	Message m2(m1);
	m2 = m2;
	m2.save(f1);
	f1.show(std::cout);
	Message * mp = new Message("asdfgh");
	Folder f2 = f1;
	f2 = f2;
	mp->save(f2);
	f2.show(std::cout);
	delete mp;
	f2.show(std::cout);
	return 0;
} 
