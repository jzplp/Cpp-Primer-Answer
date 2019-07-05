#include<iostream> 
#include<string>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<sstream>

int main()
{
	std::ifstream ifs("1.txt");
	std::vector<std::string> lines;
	std::map<std::string, std::set<size_t>> dict;
	
	std::string s;
	size_t i = 0;
	while(std::getline(ifs, s))
	{
		++i;
		lines.push_back(s);
		std::istringstream l(s);
		std::string word;
		while(l >> word)
			dict[word].insert(i);
	}
	
	while(true)
	{
		std::cout << "enter word to look for, or q to quit: ";
		std::string s;
		if(!(std::cin >> s) || s == "q")
			break;
		std::cout << s << " occurs " << dict[s].size() << (std::string(" time") + ((dict[s].size() > 1) ? "s" : "" )) << std::endl;
		for(size_t i : dict[s])
			std::cout << "\t" << "(line " << i << " )  " << lines[i - 1] << std::endl;
		std::cout << std::endl;
	}
	return 0;	 
}
