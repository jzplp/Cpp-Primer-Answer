#ifndef TREE_H
#define TREE_H

class Tree
{
public:
    Tree() : Tree(0, nullptr, nullptr) { }
    Tree(int d) : Tree(d, nullptr, nullptr) { }
    Tree(int d, Tree * l, Tree * r) : data(d), left(l), right(r) { }
private:
    int data = 0;
    Tree * left = nullptr;
    Tree * right = nullptr;
};

#endif
