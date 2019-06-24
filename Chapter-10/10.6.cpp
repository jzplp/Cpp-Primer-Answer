#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	std::vector<int> v{1,2,3,4,5,6,7,8,9,0};
	
	std::fill_n(v.begin(), v.size(), 0);
	
	for(int i : v)
		std::cout << i << " ";
	std::cout << std::endl;
	
	return 0;
}
