#ifndef TREE_H
#define TREE_H

#include<iostream>

class Tree
{
	friend bool operator==(const Tree & t1, const Tree & t2);
	friend std::ostream & operator<<(std::ostream & os, const Tree & t);
	friend std::istream & operator>>(std::istream & is, Tree & t);
public:
    Tree() : Tree(0, nullptr, nullptr) { }
    Tree(int d) : Tree(d, nullptr, nullptr) { }
    Tree(int d, Tree * l, Tree * r) : data(d), left(l), right(r) { }
    explicit operator bool() const;
private:
    int data = 0;
    Tree * left = nullptr;
    Tree * right = nullptr;
};

bool operator==(const Tree & t1, const Tree & t2)
{
	return (t1.data == t2.data && t1.left == t2.left && t1.right == t2.right);
}
bool operator!=(const Tree & t1, const Tree & t2)
{
	return !(t1 == t2);
}

std::ostream & operator<<(std::ostream & os, const Tree & t)
{
	os << t.data;
	return os;
}

std::istream & operator>>(std::istream & is, Tree & t)
{
	is >> t.data;
	if(!is)
		t.data = 0;
	return is;
}

Tree::operator bool() const
{
	if(data == 0 && left == nullptr && right == nullptr)
		return false;
	return true;
}

#endif

