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
	
	for(int i : v1)
		std::cout << i << " ";
	std::cout << std::endl;
	for(int i : v2)
		std::cout << i << " ";
	std::cout << std::endl;	
	for(int i : v3)
		std::cout << i << " ";
	std::cout << std::endl;
	for(int i : v4)
		std::cout << i << " ";
	std::cout << std::endl;	
	for(int i : v5)
		std::cout << i << " ";
	std::cout << std::endl;
	for(std::string i : v6)
		std::cout << i << " ";
	std::cout << std::endl;
	for(std::string i : v7)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}
