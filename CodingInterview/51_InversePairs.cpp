/*
51�������е������ leetcode 493
��Ŀ���������е������������ǰ��һ�����ִ��ں�������֣���������������
��һ������ԡ�����һ�����飬�����������е�����Ե�������
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
