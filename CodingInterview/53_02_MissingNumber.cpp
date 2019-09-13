/*
53��������0��n-1��ȱʧ������ leetcode 268
��Ŀ��һ������Ϊn-1�ĵ������������е��������ֶ���Ψһ�ģ�����ÿ������
���ڷ�Χ0��n-1֮�ڡ��ڷ�Χ0��n-1��n������������ֻ��һ�����ֲ��ڸ�����
�У����ҳ�������֡�
*/
#include <vector>

using namespace std;

//����1
int missingNumber_1(vector<int>& nums) {
	int sum = 0, n = nums.size();
	for (auto &a : nums) {
		sum += a;
	}
	return 0.5 * n * (n + 1) - sum;
}

// ����2
int missingNumber_2(vector<int> &nums) {
	int res = 0;
	for (int i = 0; i < nums.size(); i++) {
		res ^= (i + 1) ^ nums[i];
	}
	return res;
}