/*
62��ԲȦ�����ʣ�µ�����
��Ŀ��0, 1, ��, n-1��n�������ų�һ��ԲȦ��������0��ʼÿ�δ����ԲȦ��
ɾ����m�����֡�������ԲȦ��ʣ�µ����һ�����֡�
*/

int lastRemaining(unsigned int n, unsigned int m) {
	if (n < 1 || m < 1)
		return -1;
	int last = 0;
	for (int i = 2; i <= n; i++)
		last = (last + m) % i;
	return last;
}