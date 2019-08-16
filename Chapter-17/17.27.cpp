#include<iostream>
#include<string>
#include<regex> 

bool valid(const std::smatch &m)
{
	if(m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}

int main()
{
	std::string postalRe = "(\\d{5})([-])?(\\d{4})?";
	std::regex r(postalRe);
	std::smatch m;
	std::string s;
	while(std::cin >> s)
	{
		std::cout << std::regex_replace(s, r, "$1-$3 ", std::regex_constants::format_no_copy) << std::endl; 
	}
	return 0;
} 

