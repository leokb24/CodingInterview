/*
43����1��n������1���ֵĴ���
��Ŀ������һ������n�����1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ���������
����12����1��12��Щ�����а���1 ��������1��10��11��12��1һ��������5�Ρ�
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