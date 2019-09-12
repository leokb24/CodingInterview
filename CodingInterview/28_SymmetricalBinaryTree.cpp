/*
28 �ԳƵĶ����� leetcode 101
��Ŀ����ʵ��һ�������������ж�һ�ö������ǲ��ǶԳƵġ����һ�ö�������
���ľ���һ������ô���ǶԳƵġ�
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