/*
53（二）：0到n-1中缺失的数字 leetcode 268
题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字
都在范围0到n-1之内。在范围0到n-1的n个数字中有且只有一个数字不在该数组
中，请找出这个数字。
*/
#include <vector>

using namespace std;

//方法1
int missingNumber_1(vector<int>& nums) {
	int sum = 0, n = nums.size();
	for (auto &a : nums) {
		sum += a;
	}
	return 0.5 * n * (n + 1) - sum;
}

// 方法2
int missingNumber_2(vector<int> &nums) {
	int res = 0;
	for (int i = 0; i < nums.size(); i++) {
		res ^= (i + 1) ^ nums[i];
	}
	return res;
}