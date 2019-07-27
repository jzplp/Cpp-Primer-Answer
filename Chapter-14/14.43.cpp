#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>

int main()
{
	std::vector<int> v{2,334,23,2353,466345,72457,3125,5166};
	int count = 0, g;
	std::cin >> g;
	bool b = std::any_of(v.begin(),v.end(), std::bind(std::modulus<int>(), std::placeholders::_1, g));
	if(b)
		std::cout << "not!" << std::endl;
	else
		std::cout << "yes!" << std::endl;
	return 0;
} 
