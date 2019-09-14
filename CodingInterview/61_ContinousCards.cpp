/*
61���˿��Ƶ�˳��
��Ŀ�����˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�
2��10Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13������С�����Կ����������֡�
*/

#include <vector>
#include <algorithm>
using namespace std;

bool isContinuous(vector<int> nums) {
	if (nums.size() != 5)
		return false;
	int minNum = 14, maxNum = -1;
	int flag = 0;

	for (auto &i : nums) {
		if (i < 0 || i > 13) return false;
		if (i == 0) continue;
		if ((flag >> i) & 1 == 1) return false;
		flag |= (1 << i);
		maxNum = max(maxNum, i);
		minNum = min(minNum, i);
		if (maxNum - minNum >= 5) return false;
	}
	return true;
}