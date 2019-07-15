#include<iostream> 
#include<string>
#include<fstream> 
#include "TextQuery.h"

void runQueries(std::ifstream & infile)
{
	TextQuery tq(infile);
	while(true)
	{
		std::cout << "enter word to look for, or q to quit: ";
		std::string s;
		if(!(std::cin >> s) || s == "q")
			break;
		print(std::cout, tq.query(s)) << std::endl;
	} 
} 

int main()
{
	std::ifstream ifs("C:\\Users\\jz\\Desktop\\1.txt");
	runQueries(ifs);
	
	return 0;	 
}



