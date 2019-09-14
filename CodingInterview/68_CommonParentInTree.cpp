/*
68：树中两个结点的最低公共祖先 leetcode 236
题目：输入两个树结点，求它们的最低公共祖先。
*/

#include "Tree.h"

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root || root == p || root == q) return root;

	TreeNode *left = lowestCommonAncestor(root->left, p, q);
	TreeNode *right = lowestCommonAncestor(root->right, p, q);
	if (left && right) return root;
	if (left) return left;
	return right;
}

