/*
3.2 ���޸������ҳ��ظ�������
��Ŀ����һ������Ϊn+1����������������ֶ���1��n�ķ�Χ�ڣ���������������
��һ���������ظ��ġ����ҳ�����������һ���ظ������֣��������޸������
���顣���磬������볤��Ϊ8������{2, 3, 5, 4, 3, 2, 6, 7}����ô��Ӧ��
������ظ�������2����3��
*/

#include <iostream>
#include <vector>
using namespace std;

int countRange(vector<int> &nums, int start, int end) {
	int cnt = 0;
	
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] >= start && nums[i] <= end) {
			cnt++;
		}
	}
	return cnt;
}
// ���ֲ���
int findDuplicationNoEdit(vector<int> &nums) {
	if (nums.empty()) return -1;
	int start = 1, end = nums.size() - 1;

	while(start < end){
		int mid = start + ((end - start) >> 2);
		int cnt = countRange(nums, start, mid);

		if (cnt > (mid - start + 1))
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}
