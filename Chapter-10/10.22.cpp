#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending = "s");

void elimDups(std::vector<std::string> &words)
{
	std::sort(words.begin(), words.end());
	std::vector<std::string>::iterator ip = std::unique(words.begin(), words.end());
	words.erase(ip, words.end());
}

bool compareSize(const std::string &s, std::string::size_type sz, bool flag)
{
	return s.size() >= sz ? flag : !flag;
}

void biggies(std::vector<std::string> &words, std::string::size_type sz)
{
	elimDups(words);
	std::stable_sort(words.begin(), words.end(), [](const std::string &s1, const std::string & s2){ return s1.size() < s2.size(); });
	std::vector<std::string>::iterator wc = std::stable_partition(words.begin(), words.end(), std::bind(compareSize, std::placeholders::_1, sz, false));
	int count = std::count_if(words.begin(), words.end(), std::bind(compareSize, std::placeholders::_1, sz, true));
	std::cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << std::endl;
	for_each(wc, words.end(), [](const std::string &s){ std::cout << s << " "; });
	std::cout << std::endl;
}

int main()
{
	std::vector<std::string> v{"1","23","345","12","2342","21"};
	biggies(v, 3);
	return 0;
} 

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending)
{
	return (ctr > 1) ? word + ending : word;
}



