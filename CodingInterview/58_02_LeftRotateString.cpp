/*
58������������ת�ַ���
��Ŀ���ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
�붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ����������ַ���"abcdefg"����
��2���ú�������������ת2λ�õ��Ľ��"cdefgab"��
*/

#include <string>

using namespace std;

void leftRotateString(string &s, int n) {
	reverse(s.begin(), s.begin() + n);
	reverse(s.begin() + n, s.end());
	reverse(s.begin(), s.end());
}