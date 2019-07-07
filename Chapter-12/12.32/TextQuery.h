#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include<iostream>
#include<fstream>
#include<memory>
#include<vector>
#include<set>
#include<map>
#include<string>
#include "StrBlob.h"

class QueryResult;

class TextQuery
{
public:
	using line_no = StrBlob::size_type;
	TextQuery(std::ifstream &);
	QueryResult query(const std::string &) const;
	
private: 
	std::shared_ptr<StrBlob> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
}; 

class QueryResult
{
	friend std::ostream & print(std::ostream &, const QueryResult &);
public:
	QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p, std::shared_ptr<StrBlob> f) : sought(s), lines(p), file(f) { } 
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
	std::shared_ptr<StrBlob> file;
};

#endif
