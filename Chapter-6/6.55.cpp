#include<iostream>
#include<vector>

int add(int a, int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int mul(int a,int b)
{
	return a*b;
}
int dif(int a, int b)
{
	return a/b;
}

int main()
{
	std::vector<int (*)(int, int)> v{&add, &sub, &mul, &dif};
	for(int (*f)(int, int) : v)
		std::cout << f(2,1) << " ";
	return 0;
}
