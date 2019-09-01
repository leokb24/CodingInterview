/*
4  ��ά�����еĲ���
��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж���
�մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ��
�������ж��������Ƿ��и�������
*/

#include <iostream>
#include <vector>
using namespace std;

bool findInSortedMatrix(vector<vector<int>> &matrix, int target) {
	if (matrix.empty() || matrix[0].empty()) return false;
	int rows = matrix.size(), cols = matrix[0].size();
	int row = 0, col = cols - 1;

	while (row < rows && col >= 0) {
		if (matrix[row][col] == target)
			return true;
		else if (matrix[row][col] < target)
			row++;
		else
			col--;
	}
	return false;
}