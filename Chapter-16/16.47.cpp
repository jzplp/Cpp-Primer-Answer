#include<iostream>
#include<utility>

template <typename F, typename T1, typename T2>
int filp(F f, T1 && t1, T2 &&t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void print1(int & v1, int && v2)
{
	std::cout << v1 << " " << v2 << std::endl;
}

int main()
{
	int i = 1;
	const int j = 2; 
	filp(print1, 1, i);
	filp(print1, 2, i);
	
	return 0;
}

