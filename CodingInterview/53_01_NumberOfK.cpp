/*
53��һ�������������������г��ֵĴ��� leetcode 34
��Ŀ��ͳ��һ�����������������г��ֵĴ���������������������{1, 2, 3, 3,
3, 3, 4, 5}������3������3����������г�����4�Σ�������4��
*/

#include <vector>
#include <algorithm>

using namespace std;

int searchRange(vector<int>& nums, int target) {
	vector<int> res(2, -1);
	auto begin = lower_bound(nums.begin(), nums.end(), target);
	if (begin == nums.end() || *begin != target) return -1;
	auto end = upper_bound(nums.begin(), nums.end(), target);

	return end - begin;
}