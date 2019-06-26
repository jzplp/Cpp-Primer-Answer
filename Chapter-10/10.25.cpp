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

bool check_size(const std::string &s, std::string::size_type sz)
{
	return s.size() < sz; 
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
	elimDups(words);
	std::stable_sort(words.begin(), words.end(), [](const std::string &s1, const std::string & s2){ return s1.size() < s2.size(); });
	std::vector<std::string>::iterator wc = std::partition(words.begin(), words.end(), std::bind(check_size, std::placeholders::_1, sz));
	std::vector<std::string>::difference_type count = words.end() - wc;
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



