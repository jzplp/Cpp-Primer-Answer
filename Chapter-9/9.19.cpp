#include<iostream>
#include<string>
#include<list>

int main()
{
	std::string s;
	std::list<std::string> d;
	while(std::cin >> s)
		d.push_back(s);
	for(std::list<std::string>::const_iterator dp = d.cbegin(); dp != d.cend(); dp++)
		std::cout << *dp << " ";
	std::cout << std::endl;
	
	return 0;
}
