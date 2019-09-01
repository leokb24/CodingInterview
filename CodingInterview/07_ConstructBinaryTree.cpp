/*
7 重建二叉树(leetcode 105)
题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
图2.6所示的二叉树并输出它的头结点。
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTreeCore(vector<int> &preorder, int pLeft, int pRight, vector<int> &inorder, int iLeft, int iRight) {
	if (pLeft > pRight || iLeft > iRight) return nullptr;
	
	int i = 0;
	for (i = iLeft; i < iRight; i++) {
		if (inorder[i] == preorder[pLeft]) break;
	}
	TreeNode *cur = new TreeNode(preorder[pLeft]);
	cur->left = buildTreeCore(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i - 1);
	cur->right = buildTreeCore(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
	return cur;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	return buildTreeCore(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}