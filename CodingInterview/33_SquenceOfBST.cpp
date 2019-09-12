/*
33�������������ĺ���������� leetcode 255
��Ŀ������һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
������򷵻�true�����򷵻�false���������������������������ֶ�������ͬ��
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