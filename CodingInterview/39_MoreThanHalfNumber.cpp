/*
39�������г��ִ�������һ�������
��Ŀ����������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���
������һ������Ϊ9������{1, 2, 3, 2, 2, 2, 5, 4, 2}����������2��������
������5�Σ��������鳤�ȵ�һ�룬������2��
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
