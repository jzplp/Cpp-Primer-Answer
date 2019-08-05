#include<iostream>
#include<string>
#include<utility>
#include "Vec.h"


int main()
{
	Vec<int> v111;
	v111.push_back(1);
	std::cout << v111[0] << std::endl;
	
	using StrVec = Vec<std::string>;
	StrVec v;
	v.push_back("123");
	v.push_back("456");
	v.push_back("789");
	v = v;
	v = {"123", "456", "789"};
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
	
	StrVec v5(std::move(v2));
	for(std::string * p = v5.begin(); p != v5.end(); ++p)
		std::cout << *p << " | ";
	std::cout << std::endl;
	
	v = std::move(v5); 
	for(std::string * p = v.begin(); p != v.end(); ++p)
		std::cout << *p << " | ";
	std::cout << std::endl;
	for(std::string * p = v5.begin(); p != v5.end(); ++p)
		std::cout << *p << " | ";
	std::cout << std::endl;
	std::cout << (v == v5) << " " << (v > v5) << " " << (v < v5) << " " << (v <= v5) << " " << (v >= v5) << " " << std::endl;
	v[1] = "12";
	std::cout << v[0] << " "<< v[1] << std::endl;
	return 0;
}









