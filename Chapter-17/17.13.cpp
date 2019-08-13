#include<iostream>
#include<vector>
#include<bitset>

void changeValue(std::bitset<10> &b, size_t i, bool value)
{
	b.set(i, value);
}

int main()
{
	std::bitset<10> b1(200);
	changeValue(b1, 2, true);
	changeValue(b1, 9, true);
	std::cout << b1 << std::endl;
	return 0;
} 
