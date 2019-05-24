#include<iostream>
#include<vector>

int main()
{
	std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
	for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		*it *= 2;
	for(std::vector<int>::const_iterator it = v.cbegin(); it != v.cend(); it++)
		std::cout << *it << " ";	
	return 0;
}
