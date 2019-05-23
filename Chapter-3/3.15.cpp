#include<iostream>
#include<vector>
#include<string>

int main()
{
	std::vector<std::string> v;
	std::string s;
	while(std::cin >> s)
		v.push_back(s);
	for(std::string i : v)
		 std::cout << i << std::endl;
	return 0;
}
