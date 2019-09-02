/*
12 �����е�·��(leetcode 79 word search)
// ��Ŀ�������һ�������������ж���һ���������Ƿ����һ������ĳ�ַ�������
// �ַ���·����·�����ԴӾ���������һ��ʼ��ÿһ�������ھ����������ҡ�
// �ϡ����ƶ�һ�����һ��·�������˾����ĳһ����ô��·�������ٴν���
// �ø��ӡ������������3��4�ľ����а���һ���ַ�����bfce����·����·���е���
// ĸ���»��߱�������������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ��
// �ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool helper(vector<vector<char>> &board, string &word, int index, int x, int y, const int &rows, const int &cols);

bool exist(vector<vector<char>> &board, string word) {
	if (board.empty() || board[0].empty()) return false;

	int rows = board.size(), cols = board[0].size();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (helper(board, word, 0, i, j, rows, cols))
				return true;
		}
	}
	return false;
}

bool helper(vector<vector<char>> &board, string &word, int index, int x, int y, const int &rows, const int &cols) {
	if (index == word.size()) return true;

	if (x < 0 || y < 0 || x >= rows || y >= cols || board[x][y] != word[index]) return false;
	char tmp = board[x][y];
	board[x][y] = '*';

	bool res = helper(board, word, index + 1, x + 1, y, rows, cols) ||
		helper(board, word, index + 1, x - 1, y, rows, cols) ||
		helper(board, word, index + 1, x, y + 1, rows, cols) ||
		helper(board, word, index + 1, x, y - 1, rows, cols);

	board[x][y] = tmp;
	return res;
}

