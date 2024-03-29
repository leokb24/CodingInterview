/*
58（二）：左旋转字符串
题目：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"abcdefg"和数
字2，该函数将返回左旋转2位得到的结果"cdefgab"。
*/

#include <string>

using namespace std;

void leftRotateString(string &s, int n) {
	reverse(s.begin(), s.begin() + n);
	reverse(s.begin() + n, s.end());
	reverse(s.begin(), s.end());
}