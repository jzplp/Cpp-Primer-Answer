#include<iostream>
#include<string>
#include<utility>
#include "Sales_data.h" 

class Token
{
	friend std::ostream & operator <<(std::ostream & os, const Token &t);
public:
	Token() : tok(INT), ival{0} { }
	Token(const Token &t) : tok(t.tok) { copyUnion(t); }
	Token & operator=(const Token &);
	Token(Token &&t) noexcept;
	Token & operator=(Token &&) noexcept;
	~Token();
	Token & operator=(const std::string &);
	Token & operator=(const Sales_data &);
	Token & operator=(char);
	Token & operator=(int);
	Token & operator=(double);
private:
	enum {INT, CHAR, DBL, STR, SALE} tok;
	union {
		char cval;
		int ival;
		double dval;
		std::string sval;
		Sales_data saval;
	};
	void copyUnion(const Token &);
	void moveUnion(Token &&);
};

Token::~Token()
{
	if(tok == STR)
		sval.~basic_string();
	if(tok == SALE)
		saval.~Sales_data();
}

Token & Token::operator=(int i)
{
	if(tok == STR)
		sval.~basic_string();
	if(tok == SALE)
		saval.~Sales_data();
	ival = i;
	tok = INT;
	return *this;
}

Token & Token::operator=(const std::string & s)
{
	if(tok == SALE)
		saval.~Sales_data();
	if(tok == STR)
		sval = s;
	else
		new (&sval) std::string(s);
	tok = STR;
	return *this;
}

Token & Token::operator=(const Sales_data & s)
{
	if(tok == STR)
		sval.~basic_string();
	if(tok == SALE)
		saval = s;
	else
		new (&saval) Sales_data(s);
	tok = SALE;
	return *this;
}

Token & Token::operator=(char c)
{
	if(tok == CHAR)
		sval.~basic_string();
	if(tok == SALE)
		saval.~Sales_data();
	cval = c;
	tok = CHAR;
	return *this;
}

Token & Token::operator=(double d)
{
	if(tok == DBL)
		sval.~basic_string();
	if(tok == SALE)
		saval.~Sales_data();
	dval = d;
	tok = DBL;
	return *this;
}

void Token::copyUnion(const Token & t)
{
	switch(t.tok)
	{
		case INT:
			ival = t.ival;
			break;
		case CHAR:
			cval = t.cval;
			break;
		case DBL:
			dval = t.dval;
			break;
		case STR:
			new (&sval) std::string(t.sval);
			break;
		case SALE:
			new (&saval) Sales_data(t.saval);
	}
}

void Token::moveUnion(Token && t)
{
	switch(t.tok)
	{
		case INT:
			ival = t.ival;
			break;
		case CHAR:
			cval = t.cval;
			break;
		case DBL:
			dval = t.dval;
			break;
		case STR:
			new (&sval) std::string(std::move(t.sval));
			break;
		case SALE:
			new (&saval) Sales_data(std::move(t.saval));
			break;
	}
}


Token & Token::operator=(const Token &t)
{
	if(tok == STR && t.tok != STR)
		sval.~basic_string();
	if(tok == SALE && t.tok != SALE)
		saval.~Sales_data();
	if(tok == STR && t.tok == STR)
		sval = t.sval;
	else if(tok == SALE && t.tok == SALE)
		saval = t.saval;
	else
		copyUnion(t);
	tok = t.tok;
	return *this;
}

Token::Token(Token &&t) noexcept : tok(t.tok)
{
	moveUnion(std::move(t));
}

Token & Token::operator=(Token &&t) noexcept
{
	if(&t == this)
		return *this;
	if(tok == STR && t.tok != STR)
		sval.~basic_string();
	if(tok == SALE && t.tok != SALE)
		saval.~Sales_data();
	if(tok == STR && t.tok == STR)
		sval = std::move(t.sval);
	else if(tok == SALE && t.tok == SALE)
		saval = std::move(t.saval);
	else
		moveUnion(std::move(t));
	return *this;
}

std::ostream & operator<<(std::ostream & os, const Token &t)
{
	switch(t.tok)
	{
		case Token::INT:
			std::cout << "INT " << t.ival;
			break;
		case Token::CHAR:
			std::cout << "CHAR " << t.cval;
			break;
		case Token::DBL:
			std::cout << "DBL " << t.dval;
			break;
		case Token::STR:
			std::cout << "STR " << t.sval;
			break;
		case Token::SALE:
			std::cout << "SALE " << t.saval;
			break;
	}
	return os;
}

int main()
{
	Sales_data a(std::string("qweasd"), 1, 2.0), b(std::string("qweasd"), 2, 3.0);
	Token t, t1;
	std::cout << t << std::endl;
	t = 3;
	std::cout << t << std::endl;
	t = 'q';
	std::cout << t << std::endl;
	t = 3.14;
	std::cout << t << std::endl;
	t = std::string("qwerty");
	std::cout << t << std::endl;
	t = std::string("qaz");
	std::cout << t << std::endl;
	t = a;
	std::cout << t << std::endl;
	t = std::move(t);
	std::cout << t << std::endl;
	t1 = b;
	t = std::move(t1);
	std::cout << t << std::endl;
	std::cout << t1 << std::endl;
	return 0;
} 

