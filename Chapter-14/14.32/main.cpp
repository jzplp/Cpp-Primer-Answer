#include<iostream>
#include<string>
#include<utility>
#include<memory> 
#include "StrBlob.h"

struct classTest
{
	classTest(StrBlob &b) : p(b) { }
	StrBlobPtr p;
	std::string & operator*()
	{
		return *p;
	}
	std::string * operator->()
	{
		return p.operator->(); 
	}
}; 

int main()
{
	StrBlob b({"123","234","345"});
	classTest ct(b);
	std::cout << *ct << " " << ct->size() << std::endl;
	return 0;
} 

