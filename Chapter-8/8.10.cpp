#include<iostream>
#include<sstream>
#include<string>
#include<fstream>

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		std::cout << "No input files!" << std::endl;
		return -1;
	}
	std::ifstream ifile(argv[1]);
	std::string line;
	while(getline(ifile, line))
	{
		std::istringstream is(line);
		std::string word;
		while(is >> word)
			std::cout << word << " ";
	}
	std::cout << std::endl;
	return 0;
} 

