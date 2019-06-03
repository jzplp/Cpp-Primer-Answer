#include<iostream>

int add ()
{
	static int x = 0;
	return x++;
}

int main()
{
	for (int i = 0; i <10; ++i)
		std::cout << add() << " ";
	return 0;
}

