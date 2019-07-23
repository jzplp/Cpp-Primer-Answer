#include<iostream>

struct ITE
{
	int operator()(int a, int b, int c)
	{
		if(a)
			return b;
		return c;
	}
};

int main()
{
	ITE i1, i2;
	std::cout << i1(1,2,3) << " " << i2(0,1,2) << std::endl;
	return 0;
}
