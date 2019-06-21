#include<iostream>
#include<string>


std::string addStr(const std::string &st, const std::string &pre, const std::string &suf)
{
	std::string s(st);
	s.insert(s.begin(), pre.cbegin(),pre.cend());
	s.append(suf);
	return s;
}

int main()
{
	std::string s = addStr("Hel", "Mr. ", " Jr.");
	std::cout << s << std::endl;

	return 0;
}
