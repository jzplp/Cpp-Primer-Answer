#include<iostream>
#include<iomanip>
#include<cmath>

int main()
{
	std::cout << std::uppercase <<
	"default format: " << 100 * sqrt(2.0) << '\n' <<
	"scientific: " << std::scientific << 100 * sqrt(2.0) << '\n' <<
	"fixed decimal: " << std::fixed << 100 * sqrt(2.0) << '\n' <<
	"hexadecimal: " << std::hexfloat << 100 * sqrt(2.0) << '\n' <<
	"use default: " << std::defaultfloat << 100 * sqrt(2.0) << '\n' <<
	std::nouppercase << std::endl;
	return 0;
}
