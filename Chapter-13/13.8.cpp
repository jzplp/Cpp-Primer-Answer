#include<string>
#include<iostream> 

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr & hp): ps(new std::string(*hp.ps)), i(hp.i) { }
	std::ostream & print(std::ostream & os)
	{
		os << *ps << " " << i;
		return os;
	}
	HasPtr & operator=(const HasPtr & hp);
private:
	std::string *ps;
	int i;
};

HasPtr & HasPtr::operator=(const HasPtr & hp)
{
	*ps = *(hp.ps);
	i = hp.i;
	return *this;
}

int main()
{
	HasPtr a("12345"), c("67890");
	a.print(std::cout) << std::endl;
	HasPtr b = a;
	b.print(std::cout) << std::endl;
	b = c;
	b.print(std::cout) << std::endl;
	return 0;
}
