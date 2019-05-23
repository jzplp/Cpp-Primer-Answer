#include<iostream>
#include<vector>
#include<string>

int main()
{
	std::vector<std::string> v;
	std::string s;
	while(std::cin >> s)
		v.push_back(s);
	for(std::string &ss : v)
		for(char &c : ss)
			c = toupper(c);

	for(std::string ss : v)
		std::cout << ss <<std::endl;
	return 0;
}
