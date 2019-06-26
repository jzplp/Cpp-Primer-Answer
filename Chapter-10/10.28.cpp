#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<deque>
#include<iterator>

int main()
{
	std::vector<int> v{1,2,3,4,5,6,7,8,9};
	std::list<int> l;
	std::deque<int> d;
	std::vector<int> v2;
	
	std::copy(v.cbegin(), v.cend(), std::inserter(l, l.begin()));
	std::copy(v.cbegin(), v.cend(), std::back_inserter(v2));
	std::copy(v.cbegin(), v.cend(), std::front_inserter(d));
	
	for(int i : l)
		std::cout << i << " ";
	std::cout << std::endl;
	for(int i : v2)
		std::cout << i << " ";
	std::cout << std::endl;
	for(int i : d)
		std::cout << i << " ";
	std::cout << std::endl;
	
	return 0;
} 



