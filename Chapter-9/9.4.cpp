#include<iostream>
#include<vector>

bool find(std::vector<int>::const_iterator cbeg,std::vector<int>::const_iterator cend, int val)
{
	while(cbeg != cend)
		if(*cbeg++ == val)
			return true;
	return false; 
}

int main()
{
	std::vector<int> v{1,2,3,4,5};
	std::cout << find(v.cbegin(), v.cend(), 6) << std::endl;
	return 0;
}
