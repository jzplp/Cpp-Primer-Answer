#include<iostream>
#include<string>

class TreeNode
{
public:
	
	TreeNode(std::string s = std::string()) : value(s), count(new int(1)), left(nullptr), right(nullptr) { }
	TreeNode(const TreeNode & tn) : value(tn.value), count(tn.count), left(tn.left), right(tn.right) { ++*count; }
	~TreeNode();
	TreeNode & operator=(const TreeNode & tn);
private:
	
	void destory_subTree();
	
	std::string value;
	int * count;
	TreeNode *left;
	TreeNode *right;
};

void TreeNode::destory_subTree()
{
	if(left != nullptr)
	{
		left->destory_subTree();
		delete left;
		left = nullptr;
	}
	if(right != nullptr)
	{
		right->destory_subTree();
		delete right;
		right = nullptr;
	}
}

TreeNode::~TreeNode()
{
	if(--*count == 0)
	{
		delete count;
		destory_subTree();
	}
}

TreeNode & TreeNode::operator=(const TreeNode & tn)
{
	++*tn.count;
	if(--*count == 0)
	{
		delete count;
		destory_subTree();
	}
	value = tn.value;
	count = tn.count;
	left = tn.left;
	right = tn.right;
	return *this;
}

class BinStrTree
{
public:
	BinStrTree(TreeNode * tn = nullptr) : root(tn), count(new int(1)) { }
	BinStrTree(const BinStrTree & bst) : root(bst.root), count(bst.count) { ++*count; };
	BinStrTree & operator=(const BinStrTree & bst);
	~BinStrTree();
private:
	
	TreeNode *root;
	int * count;
};

BinStrTree::~BinStrTree()
{
	if(--*count == 0)
	{
		delete root;
		delete count;
	}
}

BinStrTree & BinStrTree::operator=(const BinStrTree & bst)
{
	++*bst.count;
	if(--*count == 0)
	{
		delete root;
		delete count;
	}
	root = bst.root;
	count = bst.count;
	return *this;
}

int main()
{
	TreeNode tna("123");
	TreeNode tnb = tna;
	tnb = tnb;
	BinStrTree bst(new TreeNode(tnb));
	
	return 0;
}
