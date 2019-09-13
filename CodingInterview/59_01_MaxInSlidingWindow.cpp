/*
59��һ�����������ڵ����ֵ leetcode 239
��Ŀ������һ������ͻ������ڵĴ�С�����ҳ����л�������������ֵ�����磬
�����������{2, 3, 4, 2, 6, 2, 5, 1}���������ڵĴ�С3����ôһ������6��
�������ڣ����ǵ����ֵ�ֱ�Ϊ{4, 4, 6, 6, 6, 5}��
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