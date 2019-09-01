/*
3.1 数组中的重复数字(leetcode 287)
题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
那么对应的输出是重复的数字2或者3。
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一 循环排序
int findDuplicate1(vector<int> &nums) {
	if (nums.empty())
		return -1;

	int n = nums.size();
	for (int i = 0; i < n; i++) {
		while (nums[i] != i + 1) {
			if (nums[i] == nums[nums[i] - 1]) return nums[i];
			swap(nums[i], nums[nums[i] - 1]);
		}
	}
	return -1;
}

// 方法二 快慢指针，当做链表有环去做
int findDuplicate2(vector<int> &nums) {
	int slow = 0, fast = 0, t = 0;
	while (true) {
		slow = nums[slow];
		fast = nums[nums[fast]];
		if (slow == fast) break;
	}
	while (true) {
		slow = nums[slow];
		t = nums[t];
		if (slow == t) break;  // 找到环的入口
	}
	return slow;
}
