/*
45���������ų���С���� leetcode 179
��Ŀ������һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ
�ӳ���������������С��һ����������������{3, 32, 321}�����ӡ����3����
�����ųɵ���С����321323��
*/

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string largestNumber(vector<int> &nums) {
	if (nums.empty()) return "";
	sort(nums.begin(), nums.end(), [&](int x, int y) {
		return to_string(x) + to_string(y) > to_string(y) + to_string(x);
	});
	
	string res = "";
	for (auto &i : nums) {
		res += to_string(i);
	}

	return res[0] == '0' ? "0" : res;
}