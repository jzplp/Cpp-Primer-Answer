#include<iostream>
#include<iomanip>
#include<cmath>

int main()
{
	std::cout << std::uppercase << std::left <<  
	std::setw(10) << 100 * sqrt(2.0) << '\n' <<
	std::setw(10) << 100 * sqrt(3.0) << '\n' <<
	std::setw(10) << 100 * sqrt(4.0) << '\n' <<
	std::setw(10) << 100 * sqrt(5.0) << '\n' <<
	std::nouppercase << std::endl;
	return 0;
}
