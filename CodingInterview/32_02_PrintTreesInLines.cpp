/*
32�����������д��ϵ��´�ӡ������ leetcode 102
��Ŀ�����ϵ��°����ӡ��������ͬһ��Ľ�㰴�����ҵ�˳���ӡ��ÿһ��
��ӡ��һ�С�
*/

#include "Tree.h"
#include <queue>
#include <iostream>

using namespace std;

void printTreesInLines(TreeNode *pRoot) {
	if (!pRoot) return;
	queue<TreeNode*> q{ { pRoot} };
	while (!q.empty()) {
		for (int i = q.size(); i > 0; i--) {
			TreeNode *pNode = q.front();
			q.pop();
			cout << pNode->val << " ";
			if (pNode->left)
				q.push(pNode->left);
			if (pNode->right)
				q.push(pNode->right);
		}
		cout << endl;
	}
}