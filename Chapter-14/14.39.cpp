#include<iostream>
#include<string> 
#include<vector>
#include<fstream>
#include<algorithm>

struct Comp
{
	Comp(int i = 0) : a(i) { }
	bool operator()(const std::string & s)
	{
		if(s.size() == a)
			return true;
		return false;
	}
	int a;
};

int main()
{
	std::ifstream ifs("1.txt");
	std::vector<std::string> v;
	std::string s;
	while(ifs >> s)
		v.push_back(s);
	int count = 0;
	for(int i = 1; i != 10; ++i)
		count += std::count_if(v.begin(), v.end(), Comp(i));
	std::cout << count << " " << (v.size() - count) << std::endl;
	return 0;
}
