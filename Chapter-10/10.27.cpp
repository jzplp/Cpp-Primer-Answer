#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<iterator>

int main()
{
	std::vector<int> v{1,1,2,2,3,4,5,12};
	std::list<int> l;
	std::unique_copy(v.cbegin(), v.cend(), std::back_inserter(l));
	for(int i : l)
		std::cout << i << " ";
	std::cout << std::endl;
	
	return 0;
} 



