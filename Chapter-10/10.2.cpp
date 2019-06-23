#include<iostream>
#include<string>
#include<list>
#include<algorithm>

int main()
{
	std::list<std::string> v;
	std::string s;
	while(std::cin >> s)
		v.push_back(s);
	std::cout << std::count(v.cbegin(), v.cend(), "1") << std::endl;
	
	return 0;
}
