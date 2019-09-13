/*
57��һ������Ϊs���������� leetcode 1
��Ŀ������һ����������������һ������s���������в�����������ʹ������
�ĺ�������s������ж�����ֵĺ͵���s���������һ�Լ��ɡ�
*/

#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		int sum = nums[left] + nums[right];
		if (sum == target)
			return{ nums[left], nums[right] };
		else if (sum < target)
			right--;
		else left++;
	}
	return{};
}