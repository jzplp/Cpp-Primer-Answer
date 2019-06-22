#include<iostream>
#include<string>
#include<vector>

int main()
{
	std::vector<std::string> v{"1","2","3","4","5"};
	int sum = 0;
	for(const std::string &s : v)
		sum += stoi(s);
	std::cout << sum << std::endl;
	
	return 0;
}
