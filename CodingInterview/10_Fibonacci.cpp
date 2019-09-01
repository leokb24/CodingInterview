/*
10 쳲���������
��Ŀ��дһ������������n����쳲�������Fibonacci�����еĵ�n�
*/

long long getFibonacci(unsigned n) {
	int res[2] = { 0, 1 };
	if (n <= 2)
		return res[n - 1];

	long long fibMinusOne = 1;
	long long fibMinusTwo = 0;
	long long fibN = 0;

	for (int i = 2; i < n; i++) {
		fibN = fibMinusOne + fibMinusTwo;
		fibMinusTwo = fibMinusOne;
		fibMinusOne = fibN;
	}
	return fibN;
}