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
	virtual Query_base * clone() const & = 0;
	virtual Query_base * clone() && = 0;
};

class Query
{
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
public:
	Query(const std::string &);
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }
	std::string rep() const { return q->rep(); }
	
	~Query() { delete q; }
	Query(const Query & rhs) : q(rhs.q->clone()) { }
	Query(Query && rhs) : q(rhs.q) { rhs.q = nullptr; }
	Query & operator=(const Query &rhs);
	Query & operator=(Query &&rhs);
private:
	Query(Query_base * query) : q(query) { }
	Query_base * q;
};

class WordQuery : public Query_base
{
	friend class Query;
	WordQuery(const std::string &s) : query_word(s) { }
	QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
	std::string rep() const { return query_word; }
	
	Query_base * clone() const & { return new WordQuery(*this); }
	Query_base * clone() && { return new WordQuery(std::move(*this)); }
	
	std::string query_word;
}; 

class NotQuery : public Query_base
{
	friend Query operator~(const Query &);
	NotQuery(const Query &q) : query(q) { }
	std::string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery &text) const;
	
	Query_base * clone() const & { return new NotQuery(*this); }
	Query_base * clone() && { return new NotQuery(std::move(*this)); }
	
	Query query;
};

class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(r), opSym(s) { }
	std::string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
	Query lhs, rhs;
	std::string opSym;
};

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query &, const Query &);
	AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") { }
	QueryResult eval(const TextQuery &text) const;
	
	Query_base * clone() const & { return new AndQuery(*this); }
	Query_base * clone() && { return new AndQuery(std::move(*this)); }
	
};

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query &, const Query &);
	OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") { }
	QueryResult eval(const TextQuery &text) const;
	
	Query_base * clone() const & { return new OrQuery(*this); }
	Query_base * clone() && { return new OrQuery(std::move(*this)); }
};

Query operator~(const Query &);
Query operator|(const Query &, const Query &);
Query operator&(const Query &, const Query &);

#endif

