#include<iostream>
#include<vector>
#include<functional>

int main()
{
	std::vector<int> v{1,2,334,23,2353,466345,72457,3125,5166};
	int count = 0, g;
	std::cin >> g;
	for(int i : v)
		if(i != (g * std::divides<int>((i,g)))
			std::cout << i << " not!" << std::endl;
	return 0;
} 
