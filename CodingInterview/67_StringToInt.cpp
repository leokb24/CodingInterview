/*
67：把字符串转换成整数 leetcode 8
题目：请你写一个函数StrToInt，实现把字符串转换成整数这个功能。当然，不
能使用atoi或者其他类似的库函数。
*/

#include <string>

using namespace std;

int myAtoi(string str) {
	if (str.empty()) return 0;
	int sign = 1, base = 0, i = 0, n = str.size();
	while (i < n && str[i] == ' ') ++i;
	if (i < n && (str[i] == '+' || str[i] == '-')) {
		sign = (str[i++] == '+') ? 1 : -1;
	}
	while (i < n && str[i] >= '0' && str[i] <= '9') {
		if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
			return (sign == 1) ? INT_MAX : INT_MIN;
		}
		base = 10 * base + (str[i++] - '0');
	}
	return base * sign;
}