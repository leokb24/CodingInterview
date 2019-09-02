/*
13 �����˵��˶���Χ
��Ŀ��������һ��m��n�еķ���һ�������˴�����(0, 0)�ĸ��ӿ�ʼ�ƶ�����
ÿһ�ο��������ҡ��ϡ����ƶ�һ�񣬵����ܽ�������������������λ֮��
����k�ĸ��ӡ����磬��kΪ18ʱ���������ܹ����뷽��(35, 37)����Ϊ3+5+3+7=18��
�������ܽ��뷽��(35, 38)����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�
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