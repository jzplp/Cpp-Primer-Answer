#include<iostream> 
#include<string>
#include<fstream>
#include<typeinfo>
#include "TextQuery.h"
#include "Query.h"

int main()
{
	std::ifstream ifs("C:\\Users\\jz\\Desktop\\1.txt");
	TextQuery tq1(ifs);
	std::string s1, s2;
	std::cin >> s1 >> s2;
	Query q1(s1), q2(s2);
	AndQuery aq(q1, q2);
	Query_base & p = aq;
	Query_base & p2 = aq;
	std::cout << (typeid(p) == typeid(p2)) << " " << (typeid(p) == typeid(AndQuery)) << std::endl;
	return 0;	 
}
