#include<iostream>
#include<string>
#include<fstream>

bool judgeWord(const std::string &s)
{
	if(s.find_first_of("qtyipdfghjkl") != std::string::npos)
		return true;
	return false;
}

int main()
{
	std::ifstream in("1.txt");
	
	
	std::string sp = "", word; 
	while(in >> word)
	{
		if(judgeWord(word))
			continue;
		if(sp.size() <= word.size())
			sp = word;
	}
	
	if(sp != "")
		std::cout << sp << std::endl;
	
	return 0;
}
