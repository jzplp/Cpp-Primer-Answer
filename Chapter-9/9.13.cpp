#include<iostream>
#include<vector>
#include<list>

void show(std::vector<double>::const_iterator cbeg,std::vector<double>::const_iterator cend)
{
	while(cbeg != cend)
		std::cout << *cbeg++ << " ";
	std::cout << std::endl;
}

int main()
{
	std::list<int> l{1,2,3,4,5};
	std::vector<int> v{1,2,3,4,5};
	
	std::vector<double> v1(l.cbegin(), l.cend());
	std::vector<double> v2(v.cbegin(), v.cend());
	
	show(v1.cbegin(), v1.cend());
	show(v2.cbegin(), v2.cend());
	
	return 0;
}
