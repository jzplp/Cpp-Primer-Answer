#ifndef TREE_H
#define TREE_H

class Tree
{
	friend bool operator==(const Tree & t1, const Tree & t2);
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

#endif

