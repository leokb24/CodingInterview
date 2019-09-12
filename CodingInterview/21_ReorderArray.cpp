/*
21 调整数组顺序使奇数位于偶数前面
题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
奇数位于数组的前半部分，所有偶数位于数组的后半部分。
*/

#include <vector>
#include <iostream>
using namespace std;

//第一种情况，要保留数字相对顺序，则只能暴力求解，这里利用冒泡的思路
void reorderArray_1(vector<int> &nums) {
	int n = nums.size();
	if (n <= 1)
		return;
	
	bool isSwap = false;
	for (int i = 0; i < n; i++) {
		isSwap = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (nums[j] % 2 == 0 && nums[j + 1] % 2 == 1) {
				swap(nums[j], nums[j + 1]);
				isSwap = true;
			}
		}
		if (!isSwap)
			break;
	}
}

//第二种情况，不需要保留相对顺序，用快排思想去做
void reorderArray_2(vector<int> &nums) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		while (left <= right && nums[left] % 2 == 1) left++;
		while (left <= right && nums[right] % 2 == 0) right--;
		if (left < right)
			swap(nums[left], nums[right]);
	}
}
