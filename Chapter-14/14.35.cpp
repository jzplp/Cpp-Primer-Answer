#include<iostream>
#include<string>

class InputString
{
public:
	InputString(std::istream & in = std::cin) : is(in) { }
	std::string operator()()
	{
		std::string s;
		is >> s;
		if(!is.good())
			return std::string();
		return s;
	}
private:
	std::istream & is;
}; 

int main()
{
	InputString is(std::cin);
	std::cout << is() << "|"<< std::endl;
	return 0;
}
