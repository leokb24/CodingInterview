/*
45：把数组排成最小的数 leetcode 179
题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼
接出的所有数字中最小的一个。例如输入数组{3, 32, 321}，则打印出这3个数
字能排成的最小数字321323。
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