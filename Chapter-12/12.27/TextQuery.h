#ifndef TESTQUERY_H
#define TESTQUERY_H

#include<memory>
#include<fstream>
#include<vector>
#include<map>
#include<set>

class QueryResult;

class TextQuery
{
	
public:
	
	TextQuery(std::ifstream & infile);
	
	QueryResult query(std::string s);
	
private:
	
	std::shared_ptr<std::vector<std::string>> lines = std::make_shared<std::vector<std::string>>();
	std::map<std::string, std::set<size_t>> dict;
};

class QueryResult
{
	friend std::ostream & print(std::ostream & os, const QueryResult & q);
public:
	QueryResult(std::string s, std::shared_ptr<std::vector<std::string>> l, std::set<size_t> n) : word(s), lines(l), lineNum(n) { }
	
private:
	std::shared_ptr<std::vector<std::string>> lines;
	std::string word;
	std::set<size_t> lineNum;
};

std::ostream & print(std::ostream & os, const QueryResult & q);

#endif
