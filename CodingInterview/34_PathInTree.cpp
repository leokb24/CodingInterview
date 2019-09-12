/*
34：二叉树中和为某一值的路径 leetcode 113
题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所
有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
*/

#include "Tree.h"
#include <vector>

using namespace std;

void helper(TreeNode *pNode, int sum, vector<int> &out, vector<vector<int>> &res) {
	if (!pNode) return;
	out.push_back(pNode->val);
	if (sum == pNode->val && !pNode->left && !pNode->right) {
		res.push_back(out);
	}
	helper(pNode->left, sum - pNode->val, out, res);
	helper(pNode->right, sum - pNode->val, out, res);
	out.pop_back();
}

vector<vector<int>> pathSum(TreeNode *pRoot, int sum) {
	vector<vector<int>> res;
	vector<int> out;
	helper(pRoot, sum, out, res);
	return res;
}