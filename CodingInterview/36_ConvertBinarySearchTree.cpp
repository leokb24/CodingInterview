/*
36：二叉搜索树与双向链表
题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求
不能创建任何新的结点，只能调整树中结点指针的指向。
*/

#include "Tree.h"

void convertHelper(TreeNode *cur, TreeNode *&pre) {
	if (!cur) return;

	convertHelper(cur->left, pre);
	cur->left = pre;
	if (pre) pre->right = cur;
	pre = cur;

	convertHelper(cur->right, pre);
}

TreeNode *Convert(TreeNode *pRoot) {
	if (!pRoot) return nullptr;
	TreeNode *pre = nullptr;

	convertHelper(pRoot, pre);
	TreeNode *res = pRoot;
	while (res->left)
		res = res->left;
	
	return res;
}