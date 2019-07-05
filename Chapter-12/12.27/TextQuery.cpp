#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include "TextQuery.h"

TextQuery::TextQuery(std::ifstream & infile)
{
	std::string s;
	size_t i = 0;
	while(std::getline(infile, s))
	{
		++i;
		lines->push_back(s);
		std::istringstream l(s);
		std::string word;
		while(l >> word)
			dict[word].insert(i);
	}
}

QueryResult TextQuery::query(std::string s)
{
	QueryResult qr(s, lines, dict[s]);
	return qr;
}

std::ostream & print(std::ostream & os, const QueryResult & q)
{
	os << q.word << " occurs " << q.lineNum.size() << (std::string(" time") + ((q.lineNum.size() > 1) ? "s" : "" )) << std::endl;
	for(size_t i : q.lineNum)
		os << "\t" << "(line " << i << " )  " << (*q.lines)[i - 1] << std::endl; 
	return os;
}
