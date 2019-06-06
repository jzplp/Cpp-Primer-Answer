#include<iostream>
#include<vector>
#include<cassert>

void print(std::vector<int>::const_iterator it,std::vector<int>::const_iterator end)
{
	assert(it <= end);
	#ifndef NDEBUG
		std::cerr << __FILE__ << " " << __func__ << " " << __LINE__ << std::endl;
	#endif
	if(it != end)
	{
		std::cout << *it++ << std::endl;
		print(it, end);
	}
	return;
}

int main()
{
	std::vector<int> v{1,2,3,4,5};
	print(v.cbegin(), v.cend());
	return 0;
}
