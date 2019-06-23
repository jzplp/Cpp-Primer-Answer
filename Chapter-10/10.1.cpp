#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	std::vector<int> v;
	int i;
	while(std::cin >> i)
		v.push_back(i);
	std::cout << std::count(v.cbegin(), v.cend(), 1) << std::endl;
	
	return 0;
}
