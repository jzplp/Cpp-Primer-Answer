#include<iostream> 
#include<string>
#include<fstream> 
#include "TextQuery.h"

void runQueries(std::ifstream & infile)
{
	TextQuery tq(infile);
	
	std::cout << *(tq.query("erl").begin()) << std::endl;
	//std::cout << *(tq.query("erl").end() - 1 ) << std::endl;
	std::cout << (*(tq.query("erl").get_file()))[0] << std::endl;
	
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
	std::ifstream ifs("1.txt");
	runQueries(ifs);
	
	return 0;	 
}

