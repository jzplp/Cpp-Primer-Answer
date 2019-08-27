#include<iostream>

class Base
{
public:
	Base(): mem(1) { }
	Base(int s): mem(s) { }
	Base(const Base & b) : mem(b.mem) { }
private:
	int mem;
};

class Base1 : public virtual Base
{
public:
	Base1(): Base() { }
	Base1(int s): Base(s) { }
	Base1(const Base1 & b) : Base(b) { }
};

class Base2 : public virtual Base
{
public:
	Base2(): Base() { }
	Base2(int s): Base(s) { }
	Base2(const Base2 & b) : Base(b) { }
};

class Base3 : public virtual Base
{
public:
	Base3(): Base() { }
	Base3(int s): Base(s) { }
	Base3(const Base2 & b) : Base(b) { }
};

int main()
{
	Base b0;
	Base1 b1;
	Base2 b2;
	Base3 b3;
	b3 = b3;
	return 0;
} 

