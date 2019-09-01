/*
5���滻�ո�
��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
�������We%20are%20happy.����
*/
#include <iostream>
#include <string>
using namespace std;

void replaceBlank(string &str) {
	if (str.empty()) return;

	int originalLength = str.size(), numberOfBlank = 0;

	for (auto &c : str)
		if (c == ' ') ++numberOfBlank;

	int newLength = originalLength + 2 * numberOfBlank, indexOfOriginal = originalLength, indexOfNew = newLength;
	str.resize(newLength);

	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
		if (str[indexOfOriginal] == ' ') {
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		else
			str[indexOfNew--] = str[indexOfOriginal];
		indexOfOriginal--;
	}
}

int main() {
	string s = "asdf xcvr et";
	replaceBlank(s);
	cout << s;
	return 0;
}