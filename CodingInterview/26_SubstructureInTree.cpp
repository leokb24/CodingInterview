/*
26 树的子结构 leetcode 572
题目：输入两棵二叉树A和B，判断B是不是A的子结构
*/

#include "Tree.h"

bool isSame(TreeNode *s, TreeNode *t) {
	if (!s && !t) return true;
	if (!s || !t) return false;
	if (s->val != t->val) return false;
	return isSame(s->left, t->left) && isSame(s->right, t->right);
}

bool isSubTree(TreeNode *s, TreeNode *t) {
	if (!s) return false;
	if (isSame(s, t)) return true;

	return isSubTree(s->left, t) || isSubTree(s->right, t);
}