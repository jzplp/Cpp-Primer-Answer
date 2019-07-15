#include<iostream>
#include<string>
#include "StrVec.h"

int main()
{
	StrVec v;
	v.push_back("123");
	v.push_back("456");
	v.push_back("789");
	v = v;
	StrVec v1 = v;
	for(std::string * p = v1.begin(); p != v1.end(); ++p)
		std::cout << *p << " ";
	std::cout << std::endl;
	
	v1.reserve(10);
	std::cout << v1.size() << " " << v1.capacity() << std::endl;
	v1.resize(20, "q");
	std::cout << v1.size() << " " << v1.capacity() << std::endl;
	for(std::string * p = v1.begin(); p != v1.end(); ++p)
		std::cout << *p << " | ";
	v1.resize(5);
	std::cout << v1.size() << " " << v1.capacity() << std::endl;
	for(std::string * p = v1.begin(); p != v1.end(); ++p)
		std::cout << *p << " | ";
	std::cout << std::endl;
	StrVec v2 = {"1","2","3"}; 
	for(std::string * p = v2.begin(); p != v2.end(); ++p)
		std::cout << *p << " | ";
	std::cout << std::endl;
	
	return 0;
}

