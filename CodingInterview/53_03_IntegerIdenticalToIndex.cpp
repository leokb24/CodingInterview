/*
53����������������ֵ���±���ȵ�Ԫ��
��Ŀ������һ�������������������ÿ��Ԫ�ض�������������Ψһ�ġ�����ʵ
��һ�������ҳ�����������һ����ֵ�������±��Ԫ�ء����磬������{-3, -1,
1, 3, 5}�У�����3�������±���ȡ�
*/

#include <vector>

using namespace std;

int numSameAsIndex(vector<int> &nums)
{
	if (nums.empty())
		return -1;

	int left = 0, right = nums.size() - 1;
	while (left <= right)
	{
		int middle = left + ((right - left) >> 1);
		if (nums[middle] == middle)
			return middle;

		if (nums[middle] > middle)
			right = middle - 1;
		else
			left = middle + 1;
	}

	return -1;
}