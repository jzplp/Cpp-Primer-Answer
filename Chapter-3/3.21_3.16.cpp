#include<iostream>
#include<vector>
#include<string>

int main()
{
	std::vector<int> v1;
	std::vector<int> v2(10);
	std::vector<int> v3(10,42);
	std::vector<int> v4{10};
	std::vector<int> v5{10,42};
	std::vector<std::string> v6{10};
	std::vector<std::string> v7{10,"hi"};
	
	for(std::vector<int>::const_iterator it = v1.cbegin(); it != v1.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for(std::vector<int>::const_iterator it = v2.cbegin(); it != v2.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for(std::vector<int>::const_iterator it = v3.cbegin(); it != v3.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for(std::vector<int>::const_iterator it = v4.cbegin(); it != v4.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for(std::vector<int>::const_iterator it = v5.cbegin(); it != v5.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for(std::vector<std::string>::const_iterator it = v6.cbegin(); it != v6.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for(std::vector<std::string>::const_iterator it = v7.cbegin(); it != v7.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return 0;
}
