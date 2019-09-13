/*
53（三）：数组中数值和下标相等的元素
题目：假设一个单调递增的数组里的每个元素都是整数并且是唯一的。请编程实
现一个函数找出数组中任意一个数值等于其下标的元素。例如，在数组{-3, -1,
1, 3, 5}中，数字3和它的下标相等。
*/

#include <vector>

using namespace std;

int numSameAsIndex(vector<int> &nums)
{
	if (nums.empty())
		return -1;

	int left = 0, right = nums.size() - 1;
	while (left <= right)
	{
		int middle = left + ((right - left) >> 1);
		if (nums[middle] == middle)
			return middle;

		if (nums[middle] > middle)
			right = middle - 1;
		else
			left = middle + 1;
	}

	return -1;
}