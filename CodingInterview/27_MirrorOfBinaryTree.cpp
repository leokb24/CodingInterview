/*
27 二叉树的镜像 leetcode 101
题目：输入一个二叉树，输出它的镜像
*/

#include <stack>
#include "Tree.h"

using namespace std;

//方法1 递归
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

//方法2 辅助栈循环
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