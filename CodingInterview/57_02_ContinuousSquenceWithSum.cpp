/*
57����������Ϊs��������������
��Ŀ������һ������s����ӡ�����к�Ϊs�������������У����ٺ�������������
��������15������1+2+3+4+5=4+5+6=7+8=15�����Խ����ӡ��3����������1��5��
4��6��7��8��
*/

#include <vector>

using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) {
	vector<vector<int>> result;
	if (sum < 3)
		return result;
	int end = (sum + 1) / 2;
	int small = 1, big = 2;
	int curSum = small + big;

	while (small < big && big <= end)
	{
		if (curSum == sum)
		{
			vector<int> temp;
			for (int i = small; i <= big; i++)
				temp.push_back(i);
			result.push_back(temp);
			curSum -= (small++); //small ��ǰ��1��Ҫɨûɨ���ģ����Բ��Ǽ�ȥbig,Ҳ����big++
		}
		else if (curSum<sum)  //�ƶ�ɨ�����ֻ����ǰɨ
			curSum += (++big);
		else if (curSum>sum)
			curSum -= (small++);
	}
	return result;
}