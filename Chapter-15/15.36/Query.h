#ifndef QUERY_H
#define QUERY_H

#include<string>
#include<memory>
#include "TextQuery.h"

class Query_base
{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery &) const = 0;
	virtual std::string rep() const = 0; 
};

class Query
{
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
public:
	Query(const std::string &);
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }
	std::string rep() const { std::cout << "Query::rep()" << std::endl; return q->rep(); }
private:
	Query(std::shared_ptr<Query_base> query) : q(query) { }
	std::shared_ptr<Query_base> q;
};

class WordQuery : public Query_base
{
	friend class Query;
	WordQuery(const std::string &s) : query_word(s) { std::cout << "WordQuery(const std::string &s)" << std::endl; }
	QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
	std::string rep() const { std::cout << "WordQuery::rep()" << std::endl; return query_word; }
	
	std::string query_word;
}; 

class NotQuery : public Query_base
{
	friend Query operator~(const Query &);
	NotQuery(const Query &q) : query(q) { std::cout << "NotQuery(const Query &q)" << std::endl; }
	std::string rep() const { std::cout << "NotQuery::rep()" << std::endl; return "~(" + query.rep() + ")"; }
	//todo Test substitution function
	QueryResult eval(const TextQuery &t) const { return t.query(query.rep()); } 
	Query query;
};

class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(r), opSym(s) { std::cout << "BinaryQuery(const Query &l, const Query &r, std::string s)" << std::endl; }
	std::string rep() const { std::cout << "BinaryQuery::rep()" << std::endl; return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
	Query lhs, rhs;
	std::string opSym;
}; 

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query &, const Query &);
	AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") { std::cout << "AndQuery(const Query &left, const Query &right)" << std::endl; }
	//todo Test substitution function
	QueryResult eval(const TextQuery &t) const { return t.query("temp"); } 
};

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query &, const Query &);
	OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") { std::cout << "OrQuery(const Query &left, const Query &right)" << std::endl; }
	//todo Test substitution function
	QueryResult eval(const TextQuery &t) const { return t.query("temp"); } 
};

Query operator~(const Query &);
Query operator|(const Query &, const Query &);
Query operator&(const Query &, const Query &);

#endif
