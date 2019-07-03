#include<iostream>
#include "StrBlob.h"

int main()
{
	StrBlob b1({"1","2","3"});
	for(StrBlobPtr p(b1.begin()); !compare(p, b1.end()); p.incr())
		std::cout << p.deref() << " ";
	std::cout << std::endl;

	return 0;
} 

