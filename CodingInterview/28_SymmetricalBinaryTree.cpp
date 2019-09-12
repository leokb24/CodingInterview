/*
28 对称的二叉树 leetcode 101
题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和
它的镜像一样，那么它是对称的。
*/

#include "Tree.h"

bool isSymmetric(TreeNode *pLeft, TreeNode *pRight) {
	if (!pLeft && !pRight) return true;
	if (!pLeft || !pRight || pLeft->val != pRight->val) return false;

	return isSymmetric(pLeft->left, pRight->right) && isSymmetric(pLeft->right, pRight->left);
}

bool isSymmetric(TreeNode *pRoot) {
	if (!pRoot) return true;
	return isSymmetric(pRoot->left, pRoot->right);
}