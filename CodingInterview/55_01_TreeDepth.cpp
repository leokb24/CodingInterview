/*
55��һ���������������
��Ŀ������һ�ö������ĸ���㣬���������ȡ��Ӹ���㵽Ҷ������ξ�����
��㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
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