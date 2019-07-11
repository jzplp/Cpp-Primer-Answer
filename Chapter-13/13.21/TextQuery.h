#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include<iostream>
#include<fstream>
#include<memory>
#include<vector>
#include<set>
#include<map>
#include<string>

class QueryResult;

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

class QueryResult
{
	friend std::ostream & print(std::ostream &, const QueryResult &);
public:
	QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p, std::shared_ptr<std::vector<std::string>> f) : sought(s), lines(p), file(f) { } 
	std::set<TextQuery::line_no>::iterator begin();
	std::set<TextQuery::line_no>::iterator end();
	std::shared_ptr<std::vector<std::string>> get_file();
private:
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

#endif

