#include <iostream>
#include <vector>
#include <string>

template <typename T>
size_t vectorFind(const std::vector<T> & v, const T & t)
{
	size_t count = 0;
	for(auto p = v.cbegin(); p != v.cend(); ++p)
		if(*p == t)
			++count;
	return count;
} 

int main()
{
	std::vector<double> vd{1.0, 2.3, 3.5, 2.3};
	std::cout << vectorFind(vd, 2.3) << std::endl;
	std::vector<int> vi{1, 2, 3, 2};
	std::cout << vectorFind(vi, 2) << std::endl;
	std::vector<std::string> vs{"1.0", "2.3", "3.5", "2.3"};
	std::cout << vectorFind(vs, std::string("2.3")) << std::endl;
	return 0;
} 

