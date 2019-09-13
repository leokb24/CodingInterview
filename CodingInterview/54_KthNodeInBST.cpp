/*
54�������������ĵ�k�����
��Ŀ������һ�ö��������������ҳ����еĵ�k��Ľ�㡣
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