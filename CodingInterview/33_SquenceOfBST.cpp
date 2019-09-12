/*
33：二叉搜索树的后序遍历序列 leetcode 255
题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。
*/

#include <vector>

using namespace std;

bool verifySequenceOfBST(vector<int> &sequence, int start, int end) {
	if (start < 0 || end >= sequence.size() || start >= end)
		return true;
	int root = sequence[end];

	int i = start;
	for (; i < end; i++) {
		if (sequence[i] > root)
			break;
	}

	int j = i;
	for (; j < end; j++) {
		if (sequence[j] < root)
			return false;
	}
	
	return verifySequenceOfBST(sequence, start, i-1) && verifySequenceOfBST(sequence, i, end-1);
}