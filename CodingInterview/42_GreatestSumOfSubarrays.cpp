/*
42：连续子数组的最大和 leetcode 53
题目：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整
数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。
*/

#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int> &nums) {
	int curSum = 0, res = INT_MIN;
	for (int i = 0; i < nums.size(); i++) {
		curSum = max(curSum + nums[i], nums[i]);
		res = max(res, curSum);
	}

	return res;
}