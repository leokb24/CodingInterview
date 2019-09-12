/*
36��������������˫������
��Ŀ������һ�ö��������������ö���������ת����һ�������˫������Ҫ��
���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
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