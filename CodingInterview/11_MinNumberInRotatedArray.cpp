/*
11 ��ת�������С����
��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ����������������һ����ת�������ת�������СԪ�ء���������
{3, 4, 5, 1, 2}Ϊ{1, 2, 3, 4, 5}��һ����ת�����������СֵΪ1��
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

