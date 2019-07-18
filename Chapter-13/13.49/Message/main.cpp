#include<iostream> 
#include<utility>
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
	std::cout << std::endl;
	f2.show(std::cout);
	std::cout << std::endl;
	
	Message m5(std::move(m1));
	m5.print(std::cout) << std::endl;
	m2 = std::move(m5);
	m2.print(std::cout) << std::endl;
	std::cout << std::endl;
	f2.show(std::cout);
	Folder f5(std::move(f2));
	f5.show(std::cout);
	
	f1 = std::move(f5);
	f1.show(std::cout);
	
	return 0;
} 

