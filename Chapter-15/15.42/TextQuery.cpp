#include<iostream>
#include<fstream>
#include<memory>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<sstream>
#include "TextQuery.h"

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

TextQuery::TextQuery(std::ifstream & is) : file(new std::vector<std::string>)
{
	while(true)
	{
		std::string text;
		char c;
		while(is.get(c) && c != '.')
			text.push_back(c);
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
		if(!is)
			break; 
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

std::set<TextQuery::line_no>::iterator QueryResult::begin()
{
	return lines->begin();
}

std::set<TextQuery::line_no>::iterator QueryResult::end()
{
	return lines->end();
}

std::shared_ptr<std::vector<std::string>> QueryResult::get_file()
{
	return file;
}

std::ostream & print(std::ostream & os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << std::endl;
	for(TextQuery::line_no num : *qr.lines)
		os << "\t(line " << num+1 << ") " << *(qr.file->begin() + num) << std::endl;
	return os;
}

