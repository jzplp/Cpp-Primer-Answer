#include<iostream> 
#include<string>
#include<fstream> 
#include<memory>
#include "TextQuery.h"
#include "Query.h"

int main()
{
	std::ifstream ifs("C:\\Users\\jz\\Desktop\\1.txt");
	TextQuery tq1(ifs);
	std::string s1, s2;
	std::cin >> s1 >> s2;
	Query q1(s1), q2(s2);
	Query qand = q1 & q2;
	Query qor = q1 | q2;
	print(std::cout, q1.eval(tq1)) << std::endl;
	print(std::cout, (~q1).eval(tq1)) << std::endl;
	print(std::cout, qand.eval(tq1)) << std::endl;
	print(std::cout, qor.eval(tq1)) << std::endl;
	print(std::cout, (~(q1 & q2) & (q1 | q2)).eval(tq1)) << std::endl;
	std::cout << q1.rep() << " " << q2.rep() << " " << qand.rep() << " " << qor.rep() << std::endl;
	
	Query qq1 = q1;
	qq1 = qq1;
	print(std::cout, qq1.eval(tq1)) << std::endl;
	q1 = std::move(qq1);
	//print(std::cout, qq1.eval(tq1)) << std::endl;
	print(std::cout, q1.eval(tq1)) << std::endl;
	qq1 = std::move(qand);
	print(std::cout, qq1.eval(tq1)) << std::endl;
	qand = qor;
	print(std::cout, qand.eval(tq1)) << std::endl;
	qq1 = std::move(qand);
	print(std::cout, qor.eval(tq1)) << std::endl;
	
	return 0;	 
}
