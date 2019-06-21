#include<iostream>
#include<string>

bool find(const std::string s, std::string::size_type ps, const std::string &s2)
{
	for(std::string::const_iterator p = s2.cbegin(); p != s2.cend(); ++p, ++ps)
	{
		if(ps == s.size() || s[ps] != *p)
			return false;
	}
	return true;
}

void rep(std::string &s, const std::string &oldVal, const std::string &newVal)
{
	for(std::string::size_type ps = 0; ps != s.size(); )
	{
		if(find(s, ps, oldVal))
		{
			s.replace(ps, oldVal.size(), newVal);
			ps += newVal.size();
		}
		else
			ps++;
	}
}

int main()
{
	std::string s("qwe qwer wer 123");
	rep(s, "we", "234");
	
	std::cout << s << std::endl;

	return 0;
}
