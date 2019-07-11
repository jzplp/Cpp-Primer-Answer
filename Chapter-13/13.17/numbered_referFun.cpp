#include<iostream>

int num = 0;

struct numbered
{
	numbered() : mysn(++num) { }
	numbered(const numbered& n) :mysn(++num) {  }
	int mysn;
};

void f(const numbered &s)
{
	std::cout << s.mysn << std::endl; 
}


int main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	return 0;
}
