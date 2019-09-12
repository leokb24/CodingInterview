/*
19 正则表达式匹配 leetcode 10
题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。
*/

#include <vector>
#include <string>

using namespace std;

//方法1 递归
bool isMatch_1(string s, string p) {
	if (p.empty()) return s.empty();
	if (p.size() > 1 && p[1] == '*') {
		return isMatch_1(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') &&
			isMatch_1(s.substr(1), p));
	}
	else {
		return !s.empty() && (p[0] == '.' || s[0] == p[0]) && isMatch_1(s.substr(1), p.substr(1));
	}
}

//方法2 动态规划 dp[i][j] 表示 s[0,i) 和 p[0,j) 是否 match
bool isMatch_2(string s, string p) {
	int m = s.size(), n = p.size();
	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
	dp[0][0] = true;
	for (int i = 0; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (j > 1 && p[j - 1] == '*') {
				dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
			}
			else {
				dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			}
		}
	}
	return dp[m][n];
}