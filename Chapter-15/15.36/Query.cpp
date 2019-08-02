#include<string>
#include<memory>
#include "TextQuery.h"
#include "Query.h"

Query::Query(const std::string &s) : q(new WordQuery(s)) { std::cout << "Query(const std::string &)" << std::endl; } 

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

