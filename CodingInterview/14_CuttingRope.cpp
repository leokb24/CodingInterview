/*
14 剪绳子
题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
时得到最大的乘积18。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法1 动态规划
int maxProductAfterCutting1(int length) {
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	vector<int> dp(length + 1);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= length; i++) {
		int maxProduct = 0;
		for (int j = 1; j <= i / 2; j++) {
			maxProduct = max(maxProduct, dp[j] * dp[i - j]);
		}
		dp[i] = maxProduct;
	}

	return dp[length];
}


// 方法2 贪心
int maxProductAfterCutting2(int length) {
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int timesOf3 = length / 3;
	if (length - timesOf3 * 3 == 1)
		timesOf3--;
	int timesOf2 = (length - timesOf3 * 3) / 2;

	return (int)(pow(3, timesOf3)) * (int)(pow(2, timesOf2));
}