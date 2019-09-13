/*
53（一）：数字在排序数组中出现的次数 leetcode 34
题目：统计一个数字在排序数组中出现的次数。例如输入排序数组{1, 2, 3, 3,
3, 3, 4, 5}和数字3，由于3在这个数组中出现了4次，因此输出4。
*/

#include <vector>
#include <algorithm>

using namespace std;

int searchRange(vector<int>& nums, int target) {
	vector<int> res(2, -1);
	auto begin = lower_bound(nums.begin(), nums.end(), target);
	if (begin == nums.end() || *begin != target) return -1;
	auto end = upper_bound(nums.begin(), nums.end(), target);

	return end - begin;
}