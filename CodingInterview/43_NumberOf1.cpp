/*
43：从1到n整数中1出现的次数
题目：输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。例如
输入12，从1到12这些整数中包含1 的数字有1，10，11和12，1一共出现了5次。
*/

int numberOf1Between1AndN(int n) {
	if (n < 1) return 0;
	int round = n, base = 1, count = 0;
	while (round) {
		int weight = round % 10;
		round /= 10;
		count += round * base;
		if (weight == 1)
			count += (n % base) + 1;
		else if (weight > 1)
			count += base;
		base *= 10;
	}
	return count;
}