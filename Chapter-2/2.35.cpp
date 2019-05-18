#include<iostream>
#include<typeinfo>
int main()
{
	const int i = 42;
	auto j = i;
	const auto &k = i;
	auto *p = &i;
	const auto j2 = i, &k2 = i;
	
	//typeid(X).name() 方法不能完全确定类型 
	
	std::cout << typeid(i).name() <<std::endl;
	std::cout << typeid(j).name() <<std::endl;
	std::cout << typeid(k).name() <<std::endl;
	std::cout << typeid(p).name() <<std::endl;
	std::cout << typeid(j2).name() <<std::endl;
	std::cout << typeid(k2).name() <<std::endl;
	
	return 0;
}
