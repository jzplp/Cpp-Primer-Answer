#include<iostream>
#include<algorithm>
#include<list>

int main()
{
	std::list<int> l{1,2,3,4,5,6,7,8,0,9};
	std::list<int>::const_reverse_iterator rp = std::find(l.crbegin(), l.crend(), 0);
	std::cout << *rp << std::endl;
	return 0;
} 

