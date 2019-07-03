#include<iostream>
#include<string>
#include "StrBlob.h"


int main()
{
	StrBlob b1;
	std::string s;
	while(std::cin >> s)
		b1.push_back(s);
	for(StrBlobPtr p(b1); !compare(p, b1.end()); p.incr())
		std::cout << p.deref() << " ";
	std::cout << std::endl; 

	return 0;
} 

