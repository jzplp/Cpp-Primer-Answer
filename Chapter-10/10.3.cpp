#include<iostream>
#include<vector>
#include<numeric>

int main()
{
	std::vector<int> v{1,2,3,4,5,6,7,8,9,0};
	
	std::cout << std::accumulate(v.cbegin(), v.cend(), 0) << std::endl; 
	
	return 0;
}
