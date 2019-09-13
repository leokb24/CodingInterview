/*
47：礼物的最大价值
题目：在一个m×n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值
(价值大于0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或
者向下移动一格直到到达棋盘的右下角。给定一个棋盘及其上面的礼物，请计
算你最多能拿到多少价值的礼物？
*/

#include <vector>
#include <algorithm>
using namespace std;

int getMaxValue(vector<vector<int>> values) {
	if (values.empty() || values[0].empty()) 
		return 0;
	int m = values.size(), n = values[0].size();
	vector<int> dp(n, INT_MIN);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0) dp[j] += values[i][j];
			else dp[j] = max(dp[j - 1], dp[j]) + values[i][j];
		}
	}
	return dp.back();
}