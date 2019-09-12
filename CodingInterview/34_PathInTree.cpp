/*
34���������к�Ϊĳһֵ��·�� leetcode 113
��Ŀ������һ�ö�������һ����������ӡ���������н��ֵ�ĺ�Ϊ������������
��·���������ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
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