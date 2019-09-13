/*
55（一）：二叉树的深度
题目：输入一棵二叉树的根结点，求该树的深度。从根结点到叶结点依次经过的
结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*/

#include "Tree.h"

int treeDepth(const TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;

	int left = treeDepth(pRoot->left);
	int right = treeDepth(pRoot->right);

	return (left > right) ? (left + 1) : (right + 1);
}