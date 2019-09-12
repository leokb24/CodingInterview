/*
27 �������ľ��� leetcode 101
��Ŀ������һ����������������ľ���
*/

#include <stack>
#include "Tree.h"

using namespace std;

//����1 �ݹ�
void mirrorOfTreeRecursively(TreeNode *pNode) {
	if (!pNode || (!pNode->left && !pNode->right)) return;
	
	TreeNode *pTemp = pNode->left;
	pNode->left = pNode->right;
	pNode->right = pTemp;

	if (pNode->left)
		mirrorOfTreeRecursively(pNode->left);
	if (pNode->right)
		mirrorOfTreeRecursively(pNode->right);
}

//����2 ����ջѭ��
void mirrorOfTreeIteratively(TreeNode *pRoot) {
	if (!pRoot) return;
	stack<TreeNode*> st;
	st.push(pRoot);

	while (!st.empty()) {
		TreeNode *pNode = st.top(); st.pop();

		TreeNode *pTemp = pNode->left;
		pNode->left = pNode->right;
		pNode->right = pTemp;

		if (pNode->left)
			st.push(pNode->left);
		if (pNode->right)
			st.push(pNode->right);
	}
}