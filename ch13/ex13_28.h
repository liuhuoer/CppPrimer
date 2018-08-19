#ifndef ex13_28_h
#define ex13_28_h

#include <string>

using std::string;

class TreeNode
{
public:
	TreeNode():value(string()),count(new size_t(1)),left(nullptr),right(nullptr){};
	TreeNode(const TreeNode & t):value(t.value),count(t.count),left(t.left),right(t.right){++*count;};
	TreeNode & operator=(const TreeNode & t);
	~TreeNode()
	{
		if(--*count==0)
		delete left;
		delete right;
		delete count;
	}
private:
	string value;
	size_t *count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree
{	
public:
	BinStrTree():root(new TreeNode()){}
	BinStrTree(const BinStrTree & bst):root(new TreeNode(*bst.root)){}
	BinStrTree & operator=(const BinStrTree &bst);
	~BinStrTree(){delete root;}
private:
	TreeNode *root;
};

#endif
