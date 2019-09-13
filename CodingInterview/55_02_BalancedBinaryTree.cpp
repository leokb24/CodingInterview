/*
55��������ƽ������� leetcode 110
��Ŀ������һ�ö������ĸ���㣬�жϸ����ǲ���ƽ������������ĳ��������
��������������������������1����ô������һ��ƽ���������
*/

#include "Tree.h"
#include <cstdlib>
#include <algorithm>

using namespace std;

int checkDepth(TreeNode *root) {
	if (!root) return 0;

	int left = checkDepth(root->left);
	if (left == -1) return -1;
	int right = checkDepth(root->right);
	if (right == -1) return -1;
	int diff = abs(left - right);

	if (diff > 1) return -1;
	else return 1 + max(left, right);
}

bool isBalanced(TreeNode *root) {
	if (checkDepth(root) == -1) return false;
	else return true;
}
