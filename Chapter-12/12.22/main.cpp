#include<iostream>
#include<string>
#include "StrBlob.h"

int main()
{
	StrBlob b1;
	std::string s;
	while(std::cin >> s)
		b1.push_back(s);
	for(ConstStrBlobPtr p= b1.cbegin(); !compare(p, b1.cend()); p.incr())
		std::cout << p.deref() << " ";
	std::cout << std::endl; 

	return 0;
} 

