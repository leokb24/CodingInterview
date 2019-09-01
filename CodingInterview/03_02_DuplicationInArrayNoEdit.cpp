/*
3.2 不修改数组找出重复的数字
题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至少
有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
输出是重复的数字2或者3。
*/

#include <iostream>
#include <vector>
using namespace std;

int countRange(vector<int> &nums, int start, int end) {
	int cnt = 0;
	
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] >= start && nums[i] <= end) {
			cnt++;
		}
	}
	return cnt;
}
// 二分查找
int findDuplicationNoEdit(vector<int> &nums) {
	if (nums.empty()) return -1;
	int start = 1, end = nums.size() - 1;

	while(start < end){
		int mid = start + ((end - start) >> 2);
		int cnt = countRange(nums, start, mid);

		if (cnt > (mid - start + 1))
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}
