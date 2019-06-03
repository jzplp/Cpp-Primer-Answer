#include<iostream>
#include<stdexcept>

int main()
{
	int i1,i2;
	std::cin >> i1 >> i2;
	if(i2 == 0)
		throw std::runtime_error("i2 is zero!");
	std::cout << i1/i2 << std::endl;
	return 0;
}

