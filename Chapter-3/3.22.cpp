#include<iostream>
#include<vector>
#include<string>

int main()
{
	std::vector<std::string> v;
	std::string s;
	while(std::cin >> s)
		v.push_back(s);
	for(std::vector<std::string>::iterator sit = v.begin(); sit != v.end() && !sit->empty(); sit++)
	{
		for(std::string::iterator cit = sit->begin(); cit != sit->end(); cit++)
			*cit = toupper(*cit);
		std::cout << *sit << " ";
	}
	return 0;
}
