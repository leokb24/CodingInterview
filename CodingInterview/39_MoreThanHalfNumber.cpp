/*
39：数组中出现次数超过一半的数字
题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例
如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中
出现了5次，超过数组长度的一半，因此输出2。
*/

#include <vector>

using namespace std;

bool checkMoreThanHalf(vector<int> &nums, int res) {
	int cnt = 0;
	for (auto &i : nums) {
		if (i == res)
			cnt++;
	}
	return cnt > nums.size() / 2;
}

int moreThanHalfNumber(vector<int> nums) {
	if (nums.empty()) return -1;

	int cnt = 1, res = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == res) cnt++;
		else cnt--;

		if (cnt == 0) {
			res = nums[i];
			cnt = 1;
		}
	}
	if (!checkMoreThanHalf(nums, res)) return -1;
	return res;
}
