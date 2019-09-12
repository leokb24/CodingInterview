/*
21 ��������˳��ʹ����λ��ż��ǰ��
��Ŀ������һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ������
����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�
*/

#include <vector>
#include <iostream>
using namespace std;

//��һ�������Ҫ�����������˳����ֻ�ܱ�����⣬��������ð�ݵ�˼·
void reorderArray_1(vector<int> &nums) {
	int n = nums.size();
	if (n <= 1)
		return;
	
	bool isSwap = false;
	for (int i = 0; i < n; i++) {
		isSwap = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (nums[j] % 2 == 0 && nums[j + 1] % 2 == 1) {
				swap(nums[j], nums[j + 1]);
				isSwap = true;
			}
		}
		if (!isSwap)
			break;
	}
}

//�ڶ������������Ҫ�������˳���ÿ���˼��ȥ��
void reorderArray_2(vector<int> &nums) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		while (left <= right && nums[left] % 2 == 1) left++;
		while (left <= right && nums[right] % 2 == 0) right--;
		if (left < right)
			swap(nums[left], nums[right]);
	}
}
