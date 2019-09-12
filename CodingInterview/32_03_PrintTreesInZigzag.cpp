/*
32（三）：之字形打印二叉树 leetcode 103
题目：请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺
序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，
其他行以此类推。
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