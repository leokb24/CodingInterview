/*
3.1 �����е��ظ�����(leetcode 287)
��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
��ô��Ӧ��������ظ�������2����3��
*/

#include <iostream>
#include <vector>
using namespace std;

// ����һ ѭ������
int findDuplicate1(vector<int> &nums) {
	if (nums.empty())
		return -1;

	int n = nums.size();
	for (int i = 0; i < n; i++) {
		while (nums[i] != i + 1) {
			if (nums[i] == nums[nums[i] - 1]) return nums[i];
			swap(nums[i], nums[nums[i] - 1]);
		}
	}
	return -1;
}

// ������ ����ָ�룬���������л�ȥ��
int findDuplicate2(vector<int> &nums) {
	int slow = 0, fast = 0, t = 0;
	while (true) {
		slow = nums[slow];
		fast = nums[nums[fast]];
		if (slow == fast) break;
	}
	while (true) {
		slow = nums[slow];
		t = nums[t];
		if (slow == t) break;  // �ҵ��������
	}
	return slow;
}
