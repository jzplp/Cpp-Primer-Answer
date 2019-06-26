#include<iostream>
#include<vector>
#include<iterator>
#include<fstream>
#include<string>

int main()
{
	std::ifstream ifs("1.txt");
	std::istream_iterator<std::string> is(ifs) ,eof; 
	std::vector<std::string> v(is, eof);
	
	for(std::string &s : v)
		std::cout << s << " ";
	std::cout << std::endl;
	
	return 0;
} 



