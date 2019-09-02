/*
12 矩阵中的路径(leetcode 79 word search)
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
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

