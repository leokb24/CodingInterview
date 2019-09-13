/*
57（一）：和为s的两个数字 leetcode 1
题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们
的和正好是s。如果有多对数字的和等于s，输出任意一对即可。
*/

#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		int sum = nums[left] + nums[right];
		if (sum == target)
			return{ nums[left], nums[right] };
		else if (sum < target)
			right--;
		else left++;
	}
	return{};
}