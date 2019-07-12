#include<string>
#include<iostream> 

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
	HasPtr(const HasPtr & hp): ps(new std::string(*hp.ps)), i(hp.i), use(hp.use) { ++*use; }
	std::ostream & print(std::ostream & os)
	{
		os << *ps << " " << i << " " << *use;
		return os;
	}
	
	HasPtr & operator=(const HasPtr & rhs);
	
	~HasPtr();
	
private:
	std::string *ps;
	int i;
	std::size_t *use;
};

HasPtr::~HasPtr()
{
	if(--*use == 0)
	{
		delete ps;
		delete use;
	}
}

HasPtr & HasPtr::operator=(const HasPtr & rhs)
{
	++*rhs.use;
	if(--*use == 0)
	{
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
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


