#include<iostream>
#include<string>

bool find(const std::string s, std::string::const_iterator ps, const std::string &s2)
{
	for(std::string::const_iterator p = s2.cbegin(); p != s2.cend(); ++p, ++ps)
	{
		if(ps == s.cend() || *ps != *p)
			return false;
	}
	return true;
}

void rep(std::string &s, const std::string &oldVal, const std::string &newVal)
{
	std::string::iterator ps = s.begin();
	while(ps != s.end())
	{
		if(find(s, ps, oldVal))
		{
			ps = s.erase(ps, ps + oldVal.size());
			ps = s.insert(ps, newVal.cbegin(), newVal.cend());
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
