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
	try
	{
		AndQuery & ap = dynamic_cast<AndQuery &>(p);
		print(std::cout, ap.eval(tq1)) << std::endl;
	}
	catch (std::bad_cast bc)
	{
		std::cout << "Fail!" << std::endl;
	}
	return 0;	 
}
