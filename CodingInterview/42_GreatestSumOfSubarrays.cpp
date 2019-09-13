/*
42����������������� leetcode 53
��Ŀ������һ���������飬������������Ҳ�и�����������һ���������Ķ����
�����һ�������顣������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�ΪO(n)��
*/

#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int> &nums) {
	int curSum = 0, res = INT_MIN;
	for (int i = 0; i < nums.size(); i++) {
		curSum = max(curSum + nums[i], nums[i]);
		res = max(res, curSum);
	}

	return res;
}