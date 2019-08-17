#include<iostream>
#include<iomanip>
#include<string>

int main()
{
	int a = 169;
	double d = 123.4567890123, d2 = -11;
	std::string s;
	
	std::cout << true << " " << false << std::endl;
	std::cout << std::boolalpha << true << " " << false << std::noboolalpha << std::endl;
	std::cout << std::endl;
	std::cout << a << " " << d << " " << d2 << std::endl; 
	std::cout << std::showbase << std::showpoint << std::showpos << std::uppercase
	<< std::dec << a << " " << d << " " << d2 << std::endl
	<< std::hex << a << " " << d << " " << d2 << std::endl
	<< std::oct << a << " " << d << " " << d2 << std::endl
	<< std::fixed << a << " " << d << " " << d2 << std::endl
	<< std::scientific << a << " " << d << " " << d2 << std::endl
	<< std::hexfloat << a << " " << d << " " << d2 << std::defaultfloat << std::endl
	<< std::left << std::setw(10) << a << " " << std::setw(10) << d << " " << std::setw(10) << d2 << std::endl
	<< std::right << std::setw(10) << a << " " << std::setw(10) << d << " " << std::setw(10) << d2 << std::endl
	<< std::internal << std::setw(10) << a << " " << std::setw(10) << d << " " << std::setw(10) << d2 << std::endl
	<< std::setprecision(5) << std::setw(10) << a << " " << std::setw(10) << d << " " << std::setw(10) << d2 << std::endl
	<< std::setfill('*') << std::setw(10) << a << " " << std::setw(10) << d << " " << std::setw(10) << d2 << std::endl
	<< std::setw(10) << std::setbase(16) << a << " " << std::setw(10) << d << " " << std::setw(10) << d2 << std::endl
	<< std::dec << std::nouppercase << std::noshowpos << std::noshowbase << std::noshowpoint << std::endl;
	
	std::cout << std::unitbuf << a << " " << d << " " << d2 << std::nounitbuf << std::endl;
	
	std::cin >> std::noskipws >> s >> std::skipws;
	std::cout << s << std::flush << s << std::ends;
	return 0;
}
