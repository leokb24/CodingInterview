/*
7 �ؽ�������(leetcode 105)
��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ����ö�������������
���ǰ���������������Ľ���ж������ظ������֡���������ǰ���������{1,
2, 4, 7, 3, 5, 6, 8}�������������{4, 7, 2, 1, 5, 3, 8, 6}�����ؽ���
ͼ2.6��ʾ�Ķ��������������ͷ��㡣
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