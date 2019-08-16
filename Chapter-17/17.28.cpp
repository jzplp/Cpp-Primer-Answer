#include<iostream>
#include<random>

unsigned int genRand()
{
	static std::default_random_engine e;
	static std::uniform_int_distribution<unsigned int> u(0, 100);
	return u(e);
}

int main()
{
	for(int i = 0; i != 10; ++i)
		std::cout << genRand() << " ";
	std::cout << std::endl;
	
	return 0;
} 

