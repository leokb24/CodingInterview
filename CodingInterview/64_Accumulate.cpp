/*
64����1+2+��+n
��Ŀ����1+2+��+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case
�ȹؼ��ּ������ж���䣨A?B:C����
*/

int sumSolution(int n) {
	int ans = n;
	ans && (ans += sumSolution(n - 1));
	return ans;
}