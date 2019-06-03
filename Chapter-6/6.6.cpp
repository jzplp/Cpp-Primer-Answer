#include<iostream>

int add (int i)
{
	++i;
	int j = 0;
	++j;
	static int x = 0;
	std::cout << i << " " << j << " " << x <<std::endl;
	return x++;
}

int main()
{
	for (int i = 0; i <10; ++i)
		add(i);
	return 0;
}

