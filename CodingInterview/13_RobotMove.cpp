/*
13 机器人的运动范围
题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
*/

#include <iostream>
#include <vector>

using namespace std;

int helper(int threshold, int rows, int cols, int x, int y, vector<vector<bool>> &visited);
bool check(int threshold, int rows, int cols, int x, int y, vector<vector<bool>> &visited);
int getDigitSum(int number);

int movingCount(int threshold, int rows, int cols) {
	if (threshold <= 0 || rows <= 0 || cols <= 0) return 0;

	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
	return helper(threshold, rows, cols, 0, 0, visited);
}

int helper(int threshold, int rows, int cols, int x, int y, vector<vector<bool>> &visited) {
	int count = 0;
	if (check(threshold, rows, cols, x, y, visited)) {
		visited[x][y] = true;
		count = 1 + helper(threshold, rows, cols, x + 1, y, visited) +
			helper(threshold, rows, cols, x - 1, y, visited) +
			helper(threshold, rows, cols, x, y + 1, visited) +
			helper(threshold, rows, cols, x, y - 1, visited);
	}

	return count;
}

bool check(int threshold, int rows, int cols, int x, int y, vector<vector<bool>> &visited) {
	if (x >= 0 && x < rows && y >= 0 && y < cols
		&& getDigitSum(x) + getDigitSum(y) <= threshold
		&& !visited[x][y])
		return true;
	return false;
}

int getDigitSum(int number) {
	int sum = 0;

	while (number > 0) {
		sum += number % 10;
		number /= 10;
	}

	return sum;
}