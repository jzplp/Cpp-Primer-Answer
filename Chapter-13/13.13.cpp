#include<iostream>
#include<vector>

struct X
{
	X() { std::cout << "X()" << std::endl; }
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	X & operator=(const X&) { std::cout << "X & operator=(const X&)" << std::endl; return *this; }
	~X() { std::cout << "~X()" << std::endl; }
};

X fun1(X x1)
{
	return x1;
}

X & fun2(X & x1)
{
	return x1;
}

int main()
{
	X x1;
	X x2(x1);
	X x3 = x1;
	x2 = x1; 
	
	std::cout << std::endl;
	
	X & x10  = x1;
	const X & x11 = x1;
	
	std::cout << std::endl;
	
	x2 = fun1(x1);
	x2 = fun2(x1);
	
	std::cout << std::endl;
	
	std::vector<X> vx1(3);
	std::vector<X> vx2(3, x1);
	
	return 0;
}
