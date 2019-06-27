#include<iostream>
#include<algorithm>
#include<list>
#include<vector>

int main()
{
	std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
	std::vector<int>::const_reverse_iterator rpb = v.crbegin() + 3;
	std::vector<int>::const_reverse_iterator rpe = v.crbegin() + 8;
	std::list<int> l(rpb, rpe);
	for(int i : l)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
} 

