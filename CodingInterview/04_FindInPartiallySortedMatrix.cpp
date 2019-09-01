/*
4  二维数组中的查找
题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
整数，判断数组中是否含有该整数。
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