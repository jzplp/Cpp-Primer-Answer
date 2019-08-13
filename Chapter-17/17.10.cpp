#include<iostream>
#include<vector>
#include<bitset>

int main()
{
	std::vector<int> v{1,2,3,5,8,13,21};
	std::bitset<32> b;
	for(auto i : v)
		b.set(i, true);
	std::cout << b << std::endl;
	
	return 0;
} 
