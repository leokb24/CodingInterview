/*
46：把数字翻译成字符串 leetcode 91
题目：给定一个数字，我们按照如下规则把它翻译为字符串：0翻译成"a"，1翻
译成"b"，……，11翻译成"l"，……，25翻译成"z"。一个数字可能有多个翻译。例
如12258有5种不同的翻译，它们分别是"bccfi"、"bwfi"、"bczi"、"mcfi"和
"mzi"。请编程实现一个函数用来计算一个数字有多少种不同的翻译方法。
*/

#include <vector>

using namespace std;

int numDecodings(string s) {
	int len = s.size();
	vector<int> dp(len + 1);
	dp[0] = 1;

	for (int i = 1; i <= len; i++) {
		dp[i] = s[i - 1] == '0' ? 0 : dp[i - 1];
		if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
			dp[i] += dp[i - 2];
		}
	}
	return dp.back();
}