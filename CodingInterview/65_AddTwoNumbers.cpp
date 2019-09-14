/*
65：不用加减乘除做加法
题目：写一个函数，求两个整数之和，要求在函数体内不得使用＋、－、×、÷
四则运算符号。
*/

int add(int num1, int num2) {
	int sum, carry;
	do {
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;
		num1 = sum;
		num2 = carry;
	} while (num2);
	return num1;
}