/*
59（一）：滑动窗口的最大值 leetcode 239
题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}，
*/

#include <deque>
#include <vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> res;
	deque<int> q;
	for (int i = 0; i<nums.size(); i++) {
		if (!q.empty() && i - q.front() == k) q.pop_front();
		while (!q.empty() && nums[q.back()] < nums[i])
			q.pop_back();
		q.push_back(i);
		if (i >= k - 1) res.push_back(nums[q.front()]);
	}
	return res;
}