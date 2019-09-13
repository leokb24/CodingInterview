/*
58（一）：翻转单词顺序
题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，
则输出"student. a am I"。
*/

#include <string>

using namespace std;

void reverseWords(string &s) {
	int storeIndex = 0, n = s.size();
	reverse(s.begin(), s.end());
	for (int i = 0; i < n; ++i) {
		if (s[i] != ' ') {
			if (storeIndex != 0) s[storeIndex++] = ' ';
			int j = i;
			while (j < n && s[j] != ' ') s[storeIndex++] = s[j++];
			reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
			i = j;
		}
	}
	s.resize(storeIndex);
}