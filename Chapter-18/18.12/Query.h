#ifndef QUERY_H
#define QUERY_H

#include<string>
#include<memory>
#include "TextQuery.h"

namespace chapter15
{

class Query_base
{
	friend class Query;
protected:
	using line_no = chapter10::TextQuery::line_no;
	virtual ~Query_base() noexcept = default;
private:
	virtual chapter10::QueryResult eval(const chapter10::TextQuery &) const = 0;
	virtual std::string rep() const = 0; 
};

class Query
{
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
public:
	Query(const std::string &) noexcept;
	chapter10::QueryResult eval(const chapter10::TextQuery &t) const { return q->eval(t); }
	std::string rep() const { return q->rep(); }
private:
	Query(std::shared_ptr<Query_base> query) noexcept : q(query) { }
	std::shared_ptr<Query_base> q;
};

class WordQuery : public Query_base
{
	friend class Query;
	WordQuery(const std::string &s) noexcept : query_word(s) { }
	chapter10::QueryResult eval(const chapter10::TextQuery &t) const { return t.query(query_word); }
	std::string rep() const { return query_word; }
	
	std::string query_word;
}; 

class NotQuery : public Query_base
{
	friend Query operator~(const Query &);
	NotQuery(const Query &q) noexcept : query(q) { }
	std::string rep() const { return "~(" + query.rep() + ")"; }
	chapter10::QueryResult eval(const chapter10::TextQuery &text) const;
	Query query;
};

class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s) noexcept : lhs(l), rhs(r), opSym(s) { }
	std::string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
	Query lhs, rhs;
	std::string opSym;
}; 

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query &, const Query &);
	AndQuery(const Query &left, const Query &right) noexcept : BinaryQuery(left, right, "&") { }
	chapter10::QueryResult eval(const chapter10::TextQuery &text) const;
};

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query &, const Query &);
	OrQuery(const Query &left, const Query &right) noexcept : BinaryQuery(left, right, "|") { }
	chapter10::QueryResult eval(const chapter10::TextQuery &text) const;
};

Query operator~(const Query &);
Query operator|(const Query &, const Query &);
Query operator&(const Query &, const Query &);

}//namespace chapter15 

#endif

