/*
54：二叉搜索树的第k个结点
题目：给定一棵二叉搜索树，请找出其中的第k大的结点。
*/

#include "Tree.h"

int kthSmallestDFS(TreeNode *root, int &k) {
	if (!root) return -1;
	int val = kthSmallestDFS(root->left, k);
	if (k == 0) return val;
	if (--k == 0) return root->val;
	return kthSmallestDFS(root->right, k);
}

int kthSmallest(TreeNode* root, int k) {
	return kthSmallestDFS(root, k);
}