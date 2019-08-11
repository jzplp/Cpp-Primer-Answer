#include<iostream>
#include<fstream>
#include<memory>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<sstream>
#include<tuple> 
#include "TextQuery.h"

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

TextQuery::TextQuery(std::ifstream & is) : file(new std::vector<std::string>)
{
	std::string text;
	while(std::getline(is, text))
	{
		file->push_back(text);
		int n = file->size()-1;
		std::istringstream line(text);
		std::string word;
		while(line >> word)
		{
			std::shared_ptr<std::set<line_no>> &lines = wm[word];
			if(!lines)
				lines.reset(new std::set<line_no>);
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const std::string & sought) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	std::map<std::string, std::shared_ptr<std::set<line_no>>>::const_iterator loc = wm.find(sought);
	if(loc == wm.cend())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}


std::ostream & print(std::ostream & os, const QueryResult &qr)
{
	os << std::get<0>(qr) << " occurs " << std::get<1>(qr)->size() << " " << make_plural(std::get<1>(qr)->size(), "time", "s") << std::endl;
	for(TextQuery::line_no num : *(std::get<1>(qr)))
		os << "\t(line " << num+1 << ") " << *(std::get<2>(qr)->begin() + num) << std::endl;
	return os;
}

