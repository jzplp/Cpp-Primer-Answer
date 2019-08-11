#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include<iostream>
#include<fstream>
#include<memory>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<tuple> 

class TextQuery;

typedef std::tuple<std::string, std::shared_ptr<std::set<std::vector<std::string>::size_type>>, std::shared_ptr<std::vector<std::string>>> QueryResult;

class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream &);
	QueryResult query(const std::string &) const;
	TextQuery(const TextQuery & tq) = default;
	TextQuery & operator=(const TextQuery & tq) = default;
	~TextQuery() = default;
	
private: 
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
}; 

std::ostream & print(std::ostream & os, const QueryResult &qr);

#endif

