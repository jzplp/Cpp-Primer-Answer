#include<string>
#include<memory>
#include<set>
#include<algorithm>
#include<iterator>
#include "TextQuery.h"
#include "Query.h"

namespace chapter15
{


Query::Query(const std::string &s) noexcept : q(new WordQuery(s)) { } 

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

chapter10::QueryResult OrQuery::eval(const chapter10::TextQuery &text) const
{
	chapter10::QueryResult left = lhs.eval(text), right = rhs.eval(text);
	std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return chapter10::QueryResult(rep(), ret_lines, left.get_file());
}

chapter10::QueryResult AndQuery::eval(const chapter10::TextQuery &text) const
{
	chapter10::QueryResult left = lhs.eval(text), right = rhs.eval(text);
	std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));
	return chapter10::QueryResult(rep(), ret_lines, left.get_file());	
}

chapter10::QueryResult NotQuery::eval(const chapter10::TextQuery &text) const
{
	chapter10::QueryResult result = query.eval(text);
	std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>();
	
	std::set<line_no>::iterator beg = result.begin(), end = result.end();
	line_no sz = result.get_file()->size();
	for(line_no n = 0; n != sz; ++n)
	{
		if(beg == end || *beg != n)
			ret_lines->insert(n);
		else if(beg != end)
			++beg;
	}
	return chapter10::QueryResult(rep(), ret_lines, result.get_file());	
}

}//namespace chapter15 
