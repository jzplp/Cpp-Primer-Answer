#include<iostream>
#include<string> 
int main(int argc, char *argv[])
{
	if(argc < 3)
		return -1;
	std::string s(argv[1]);
	s += argv[2];
	std::cout << s << std::endl;
	return 0;
} 

