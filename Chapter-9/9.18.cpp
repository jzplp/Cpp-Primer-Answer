#include<iostream>
#include<string>
#include<deque>

int main()
{
	std::string s;
	std::deque<std::string> d;
	while(std::cin >> s)
		d.push_back(s);
	for(std::deque<std::string>::const_iterator dp = d.cbegin(); dp != d.cend(); dp++)
		std::cout << *dp << " ";
	std::cout << std::endl;
	
	return 0;
}
