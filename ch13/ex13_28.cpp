#include "ex13_28.h"

TreeNode & TreeNode::operator=(const TreeNode &rtn)
{
	++*rtn.count;
	if(--*count==0)
	{
		delete left;
		delete right;
		delete count;
	}
	value=rtn.value;
	left=rtn.left;
	right=rtn.right;
	count=rtn.count;

	return *this;
}

BinStrTree & BinStrTree::operator=(const BinStrTree &rbst)
{
	TreeNode *t=new TreeNode(*rbst.root);
	delete root;
	root=t;

	return *this;
}

int main()
{
	return 0;
}
