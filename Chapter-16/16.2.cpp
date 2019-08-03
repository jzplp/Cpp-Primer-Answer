#include<iostream>
#include<string>

template <typename T>
int compare(const T & v1, const T & v2)
{
	if(v1 < v2)
		return -1;
	if(v2 < v1)
		return 1;
	return 0;
}

int main()
{
	std::cout << compare(1,2) << std::endl;
	std::cout << compare(std::string("123"), std::string("123")) << std::endl;
	return 0;
}
