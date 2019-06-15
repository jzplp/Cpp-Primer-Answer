#include<fstream>
#include<string>
#include<vector>
#include<iostream>

int main()
{
	std::ifstream in;
	std::string s("1.txt");
	in.open(s);
	std::vector<std::string> v;
	while(getline(in, s))
		v.push_back(s);
	
	for(const std::string &cs : v)
		std::cout << cs <<std::endl;
	
	return 0;
} 





