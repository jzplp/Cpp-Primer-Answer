#include<iostream>
#include<string>

class Token
{
	friend std::ostream & operator <<(std::ostream & os, const Token &t);
public:
	Token() : tok(INT), ival{0} { }
	Token(const Token &t) : tok(t.tok) { copyUnion(t); }
	Token & operator=(const Token &);
	~Token() { if(tok == STR) sval.~basic_string(); }
	Token & operator=(const std::string &);
	Token & operator=(char);
	Token & operator=(int);
	Token & operator=(double);
private:
	enum {INT, CHAR, DBL, STR} tok;
	union {
		char cval;
		int ival;
		double dval;
		std::string sval;
	};
	void copyUnion(const Token &);
};

Token & Token::operator=(int i)
{
	if(tok == STR)
		sval.~basic_string();
	ival = i;
	tok = INT;
	return *this;
}

Token & Token::operator=(const std::string & s)
{
	if(tok == STR)
		sval = s;
	else
		new (&sval) std::string(s);
	tok = STR;
	return *this;
}

Token & Token::operator=(char c)
{
	if(tok == CHAR)
		sval.~basic_string();
	cval = c;
	tok = CHAR;
	return *this;
}

Token & Token::operator=(double d)
{
	if(tok == DBL)
		sval.~basic_string();
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
	}
}

Token & Token::operator=(const Token &t)
{
	if(tok == STR && t.tok != STR)
		sval.~basic_string();
	if(tok == STR && t.tok == STR)
		sval = t.sval;
	else
		copyUnion(t);
	tok = t.tok;
	return *this;
}

std::ostream & operator <<(std::ostream & os, const Token &t)
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
	}
	return os;
}

int main()
{
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
	t = t;
	std::cout << t << std::endl;
	t1 = 'q';
	t = t1;
	std::cout << t << std::endl;
	
	return 0;
} 

