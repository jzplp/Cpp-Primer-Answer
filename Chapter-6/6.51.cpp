#include<iostream>

void f();
void f(int);
void f(int, int);
void f(double, double = 3.14); 

int main()
{
	f();
	f(1);
	f(1.1);
	f(1, 2);
	f(1.1, 2.1); 
	return 0;
}

void f()
{
	std::cout << "f()" << std::endl;
}
void f(int i)
{
	std::cout << "f(int)" << std::endl;
}
void f(int, int)
{
	std::cout << "f(int, int)" << std::endl;
}
void f(double, double)
{
	std::cout << "f(double, double)" << std::endl;
}

