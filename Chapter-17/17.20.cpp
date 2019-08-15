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
	std::string phoneRe = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	std::regex r(phoneRe);
	std::smatch m;
	std::string s;
	while(getline(std::cin, s))
	{
		for(std::sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
		{
			if(!valid(*it))
				std::cout << "not valid: " << it->str() << std::endl;
			else
				std::cout << "valid: " << it->str() << std::endl;
		}
	}
	return 0;
} 

