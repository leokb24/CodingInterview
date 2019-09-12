/*
32��һ���������д������´�ӡ������
��Ŀ���������´�ӡ����������ÿ����㣬ͬһ��Ľ�㰴�մ����ҵ�˳���ӡ��
*/

#include "Tree.h"
#include <queue>
#include <iostream>
using namespace std;

void printFromTopToBottom(TreeNode *pRoot) {
	if (!pRoot) return;


	queue<TreeNode*> q;
	q.push(pRoot);

	while (!q.empty()) {
		TreeNode *pNode = q.front();
		q.pop();
		cout << pNode->val << " ";

		if (pNode->left) q.push(pNode->left);
		if (pNode->right) q.push(pNode->right);
	}
}