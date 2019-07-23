#include<iostream>
#include<string>
#include<vector>

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
	std::vector<std::string> v{is(), is(), is()};
	for(const std::string &s : v)
		std::cout << s << "|";
	std::cout << std::endl; 
	return 0;
}
