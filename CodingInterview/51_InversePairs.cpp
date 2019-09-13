/*
51：数组中的逆序对 leetcode 493
题目：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组
成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
*/

#include <vector>
#include <algorithm>

using namespace std;

int mergeSort(vector<int> &nums, vector<int> &copy, int left, int right) {
	if (left >= right) return 0;

	int mid = left + (right - left) / 2;
	int res = mergeSort(copy, nums, left, mid) + mergeSort(copy, nums, mid + 1, right);

	int i = left, j = mid + 1, index = left;
	while (i <= mid && j <= right) {
		if (nums[i] <= nums[j]) {
			copy[index++] = nums[i++];
		}
		else {
			res += mid - i + 1;
			copy[index++] = nums[j++];
		}
	}
	while (i <= mid)
		copy[index++] = nums[i++];
	while (j <= right)
		copy[index++] = nums[j++];
	return res;
}

int reversePairs(vector<int> &nums) {
	vector<int> copy(nums.begin(), nums.end());
	return mergeSort(nums, copy, 0, nums.size() - 1);
}
