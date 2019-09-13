/*
55（二）：平衡二叉树 leetcode 110
题目：输入一棵二叉树的根结点，判断该树是不是平衡二叉树。如果某二叉树中
任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
*/

#include "Tree.h"
#include <cstdlib>
#include <algorithm>

using namespace std;

int checkDepth(TreeNode *root) {
	if (!root) return 0;

	int left = checkDepth(root->left);
	if (left == -1) return -1;
	int right = checkDepth(root->right);
	if (right == -1) return -1;
	int diff = abs(left - right);

	if (diff > 1) return -1;
	else return 1 + max(left, right);
}

bool isBalanced(TreeNode *root) {
	if (checkDepth(root) == -1) return false;
	else return true;
}
