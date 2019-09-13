/*
面试题44：数字序列中某一位的数字 leetcode 400
题目：数字以0123456789101112131415…的格式序列化到一个字符序列中。在这
个序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。请写一
个函数求任意位对应的数字。
*/

#include <string>

using namespace std;

int findNthDigit(int n) {
	long long len = 1, cnt = 9, start = 1;
	while (n > cnt * len) {
		n -= cnt * len;
		len++;
		cnt *= 10;
		start *= 10;
	}

	start += (n - 1) / len;
	string t = to_string(start);
	return t[(n - 1) % len] - '0';
}