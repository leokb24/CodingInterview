/*
11 旋转数组的最小数字
题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
{3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。
*/

#include <vector>
#include <exception>
using namespace std;

int minNumberInRotateArray(vector<int> nums) {
	if (nums.empty()) throw new exception("empty array");

	int left = 0, right = nums.size() - 1;
	while (left < right) {
		int mid = left + ((right - left) >> 2);
		if (nums[mid] < nums[right]) right = mid;
		else if (nums[mid] > nums[right]) left = mid + 1;
		else right--;
	}
	return nums[right];
}

