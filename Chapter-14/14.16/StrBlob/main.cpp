#include<iostream>
#include<string>
#include<utility>
#include "StrBlob.h"

int main()
{
	StrBlob b1;
	std::string s;
	while(std::cin >> s)
		b1.push_back(std::move(s));
	StrBlob b2 = b1;
	b2 = b2;
	for(ConstStrBlobPtr p= b2.cbegin(); p != b2.cend(); p.incr())
		std::cout << p.deref() << " ";
	std::cout << std::endl;
	
	std::cout << (b1 == b2) << std::endl;
	

	return 0;
} 
