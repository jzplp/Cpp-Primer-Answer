#include<iostream>

int main(int argc, char *argv[])
{
	for(size_t i = 1; i < argc; ++i)
		std::cout << argv[i] << " ";
	return 0;
}


