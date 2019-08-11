#include<iostream>
#include<tuple>
#include<string>
#include<vector>
#include<utility>

int main()
{
	std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>> t{"123", {"234","qwe"}, {"qaz", 3}};
	std::cout << std::get<0>(t) << " " << std::get<1>(t)[1] << " " <<  std::get<2>(t).second << std::endl;
	return 0;
} 
