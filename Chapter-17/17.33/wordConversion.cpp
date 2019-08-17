#include<iostream>
#include<fstream>
#include<sstream>
#include<map>
#include<string>
#include<vector>
#include<utility>
#include<stdexcept>
#include<random> 

std::map<std::string, std::vector<std::string>> buildMap(std::ifstream &map_file)
{
	std::map<std::string, std::vector<std::string>> trans_map;
	std::string key, value;
	while(map_file >> key && std::getline(map_file, value))
	{
		if(value.size() > 1)
		{
			trans_map[key];
			trans_map[key].push_back(value.substr(1));
		}
		else
			throw std::runtime_error("no rule for " + key); 
	}
	return trans_map;
}

const std::string & transform(const std::string &s, const std::map<std::string, std::vector<std::string>> &m)
{
	std::map<std::string, std::vector<std::string>>::const_iterator map_it = m.find(s);
	static std::default_random_engine e;
	if(map_it != m.cend())
	{
		if(map_it->second.size() == 1)
			return map_it->second[0];
		else
		{
			std::uniform_int_distribution<unsigned> u(0, map_it->second.size()-1);
			return map_it->second[u(e)];
		}
	}
	else
		return s;
}

void word_transform(std::ifstream &map_file, std::ifstream &input)
{
	std::map<std::string, std::vector<std::string>> trans_map = buildMap(map_file);
	std::string text;
	while(std::getline(input, text))
	{
		std::istringstream stream(text);
		std::string word;
		bool firstword = true;
		while(stream >> word)
		{
			if(firstword)
				firstword = false;
			else
				std::cout << " ";
			std::cout << transform(word, trans_map);
		}
		std::cout << std::endl;
	}
}

int main()
{
	std::ifstream map_file("C:\\Users\\jz\\Desktop\\map.txt");
	std::ifstream input("C:\\Users\\jz\\Desktop\\in.txt");
	word_transform(map_file, input);
	
	return 0;
} 




