#include<string>
#include<memory>
#include<set>
#include<algorithm>
#include<iterator>
#include<tuple> 
#include "TextQuery.h"
#include "Query.h"

Query::Query(const std::string &s) : q(new WordQuery(s)) { } 

Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs)); 
}

Query operator|(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery &text) const
{
	QueryResult left = lhs.eval(text), right = rhs.eval(text);
	std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>(std::get<1>(left)->begin(), std::get<1>(left)->end());
	ret_lines->insert(std::get<1>(right)->begin(), std::get<1>(right)->end());
	return QueryResult(rep(), ret_lines, std::get<2>(left));
}

QueryResult AndQuery::eval(const TextQuery &text) const
{
	QueryResult left = lhs.eval(text), right = rhs.eval(text);
	std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(std::get<1>(left)->begin(), std::get<1>(left)->end(), std::get<1>(right)->begin(), std::get<1>(right)->end(), std::inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, std::get<2>(left));	
}

QueryResult NotQuery::eval(const TextQuery &text) const
{
	QueryResult result = query.eval(text);
	std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>();
	
	std::set<line_no>::iterator beg = std::get<1>(result)->begin(), end = std::get<1>(result)->end();
	line_no sz = std::get<2>(result)->size();
	for(line_no n = 0; n != sz; ++n)
	{
		if(beg == end || *beg != n)
			ret_lines->insert(n);
		else if(beg != end)
			++beg;
	}
	return QueryResult(rep(), ret_lines, std::get<2>(result));	
}
