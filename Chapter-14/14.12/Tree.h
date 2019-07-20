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
private:
    int data = 0;
    Tree * left = nullptr;
    Tree * right = nullptr;
};

bool operator==(const Tree & t1, const Tree & t2)
{
	if(t1.data == t2.data && t1.left == t2.left && t1.right == t2.right )
		return true;
	return false;
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

#endif

