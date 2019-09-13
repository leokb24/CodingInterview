/*
60：n个骰子的点数 lintcode 20
题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s
的所有可能的值出现的概率。
*/

#include <vector>

using namespace std;

vector<pair<int, double>> dicesSum(int n) {
	vector<double> res(6 * n + 1, 0);
	for (int i = 1; i <= 6; ++i)
		res[i] = 1.0 / 6;
	for (int i = 2; i <= n; ++i)
		for (int j = 6 * i; j >= i; --j) {
			double sum = 0;
			for (int k = 1; k <= 6 && j - k >= i - 1; ++k)
				//需要注意的是，i - 1以内的数据不属于第n - 1次投掷，需要被过滤掉
				sum += res[j - k] * 1.0 / 6;
			res[j] = sum;
		}
	vector<pair<int, double> > ans(5 * n + 1, make_pair(0, 0));
	for (int i = 0; i < ans.size(); ++i)
		ans[i] = make_pair(n + i, res[n + i]);
	return ans;
}