/*
32（二）：分行从上到下打印二叉树 leetcode 102
题目：从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层
打印到一行。
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