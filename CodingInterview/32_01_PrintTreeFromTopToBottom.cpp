/*
32（一）：不分行从上往下打印二叉树
题目：从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。
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