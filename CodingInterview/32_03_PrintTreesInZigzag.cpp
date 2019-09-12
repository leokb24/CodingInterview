/*
32��������֮���δ�ӡ������ leetcode 103
��Ŀ����ʵ��һ����������֮����˳���ӡ������������һ�а��մ����ҵ�˳
���ӡ���ڶ��㰴�մ��ҵ����˳���ӡ���������ٰ��մ����ҵ�˳���ӡ��
�������Դ����ơ�
*/

#include "Tree.h"
#include <stack>
#include <iostream>

using namespace std;

void printTreesZigZag(TreeNode *pRoot) {
	if (!pRoot) return;
	stack<TreeNode*> st[2];
	st[0].push(pRoot);
	int level = 0;

	while (!st[0].empty() || !st[1].empty()) {
		while (!st[level].empty()) {
			TreeNode *pNode = st[level].top();
			st[level].pop();
			cout << pNode->val << " ";
			if (level == 0) {
				if (pNode->left) st[1 - level].push(pNode->left);
				if (pNode->right) st[1 - level].push(pNode->right);
			}
			else {
				if (pNode->right) st[1 - level].push(pNode->right);
				if (pNode->left) st[1 - level].push(pNode->left);
			}
		}
		level = 1 - level;
		cout << endl;
	}
}