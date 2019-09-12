/*
40：最小的k个数
题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
这8个数字，则最小的4个数字是1、2、3、4。
*/

#include <vector>

using namespace std;

int partition(vector<int> &nums, int start, int end) {
	if (start < end) {
		int mid = start + (end - start) / 2;
		int pivot = nums[mid];
		swap(nums[end], nums[mid]);

		int i = start, j = end - 1;
		while (i <= j) {
			while (i <= j && nums[i] <= pivot)
				i++;
			while (i <= j && nums[j] > pivot)
				j--;
			if (i < j)
				swap(nums[i], nums[j]);
		}
		swap(nums[i], nums[end]);
		return i;
	}
	return start;
}

vector<int> getLeastNumbers(vector<int> nums, int k) {
	if (k <= 0 || k > nums.size()) return{};
	int start = 0, end = nums.size() - 1;
	int index = partition(nums, start, end);
	vector<int> res;

	while (index != k - 1) {
		if (index > k - 1) {
			end = index - 1;
			index = partition(nums, start, end);
		}
		else {
			start = index + 1;
			index = partition(nums, start, end);
		}
	}
	for (int i = 0; i < k; i++) {
		res.push_back(nums[i]);
	}
	return res;
}
