#include<iostream>
#include<vector>

void show(std::vector<int>::const_iterator cbeg,std::vector<int>::const_iterator cend)
{
	while(cbeg != cend)
		std::cout << *cbeg++ << " ";
	std::cout << std::endl;
}

int main()
{
	std::vector<int> v1;
	std::vector<int> v2(v1);
	std::vector<int> v3{1,2,3,4,5};
	std::vector<int> v4(v3.cbegin(), v3.cend());
	std::vector<int> v5(5);
	std::vector<int> v6(5, 1);
	
	show(v1.cbegin(), v1.cend());
	show(v2.cbegin(), v2.cend());
	show(v3.cbegin(), v3.cend());
	show(v4.cbegin(), v4.cend());
	show(v5.cbegin(), v5.cend());
	show(v6.cbegin(), v6.cend());

	return 0;
}
