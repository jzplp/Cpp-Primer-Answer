#include<iostream>
#include<string>
#include<vector>

int main()
{
	std::vector<std::string> v{"1","2.1","3","4","5"};
	double sum = 0;
	for(const std::string &s : v)
		sum += stod(s);
	std::cout << sum << std::endl;
	
	return 0;
}
