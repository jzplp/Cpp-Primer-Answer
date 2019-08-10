#include<iostream>
#include<string>

template <typename T>
std::ostream & print(std::ostream & os, const T & t)
{
	return os << t;
} 

template <typename T, typename ... Args>
std::ostream & print(std::ostream & os, const T & t, const Args & ... rest)
{
	os << t << ", ";
	return print(os, rest...);
}

int main()
{
	print(std::cout, 1) << std::endl;
	print(std::cout, 1, "123") << std::endl;
	print(std::cout, 1, "123", 3.123, std::string("qwert"), -5) << std::endl;
	return 0;
}

