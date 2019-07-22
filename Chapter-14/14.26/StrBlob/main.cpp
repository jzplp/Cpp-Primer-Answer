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
	StrBlobPtr pn = b1.begin();
	const StrBlobPtr pn1 = b1.begin();
	std::cout << pn[0] << " " << pn1[0] << " " << b1.cbegin().incr()[0] << std::endl; 
	b2 = b2;
	const StrBlob bn = b1;
	b1[1] = std::string("1234");
	std::cout << b1[0] << " " << b1[1] << std::endl;
	std::cout << bn[0] << " " << bn[1] << std::endl;
	for(ConstStrBlobPtr p= b2.cbegin(); p != b2.cend(); p.incr())
		std::cout << p.deref() << " ";
	std::cout << std::endl;
	std::cout << (b1 == b2) << std::endl;
	std::cout << (b1 > b2) << " " << (b1 < b2) << " " <<  (b1 >= b2) << " " << (b1 <= b2) << " " << std::endl;
	StrBlobPtr p1 = b1.begin(), p2 = b1.begin().incr();
	std::cout << (p1 > p2) << " " << (p1 < p2) << " " <<  (p1 >= p2) << " " << (p1 <= p2) << " " << std::endl;	
	ConstStrBlobPtr p3 = b1.cbegin(), p4 = b1.cbegin().incr();
	std::cout << (p3 > p4) << " " << (p3 < p4) << " " <<  (p3 >= p4) << " " << (p3 <= p4) << " " << std::endl;	
	return 0;
} 
