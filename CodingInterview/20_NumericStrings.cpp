/*
20 表示数值的字符串 leetcode 65
题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
“1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是
*/

#include <string>

using namespace std;

bool isNumber(string s) {
	bool num = false, numAfterE = true, dot = false, exp = false, sign = false;
	int n = s.size();

	for (int i = 0; i < n; i++) {
		if (s[i] == ' ') {
			if (i < n - 1 && s[i + 1] != ' ' && (num || dot || exp || sign)) return false;
		}
		else if (s[i] == '+' || s[i] == '-') {
			if (i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ') return false;
			sign = true;
		}
		else if (s[i] >= '0' && s[i] <= '9') {
			num = true;
			numAfterE = true;
		}
		else if (s[i] == '.') {
			if (dot || exp) return false;
			dot = true;
		}
		else if (s[i] == 'e') {
			if (exp || !num) return false;
			exp = true;
			numAfterE = false;
		}
		else
			return false;
	}
	return num && numAfterE;
}