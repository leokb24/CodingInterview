/*
15 二进制中1的个数
题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。
*/

int numberOfOne(int n) {
	int cnt = 0;
	while (n) {
		cnt++;
		n &= (n - 1);
	}

	return cnt;
}