#include<iostream>
#include<random>

unsigned int genRand(unsigned int se = 32767, int min = 0, int max = 100)
{
	static unsigned stSe = 32767;
	static std::default_random_engine e;
	std::uniform_int_distribution<unsigned int> u(min, max);
	if(stSe != se)
		e.seed(se);
	return u(e);
}

int main()
{
	for(int i = 0; i != 10; ++i)
		std::cout << genRand(i*432223+45345, i, 100) << " ";
	std::cout << std::endl;
	
	return 0;
} 

