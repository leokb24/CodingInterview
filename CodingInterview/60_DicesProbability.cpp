/*
60��n�����ӵĵ��� lintcode 20
��Ŀ����n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs������n����ӡ��s
�����п��ܵ�ֵ���ֵĸ��ʡ�
*/

#include <vector>

using namespace std;

vector<pair<int, double>> dicesSum(int n) {
	vector<double> res(6 * n + 1, 0);
	for (int i = 1; i <= 6; ++i)
		res[i] = 1.0 / 6;
	for (int i = 2; i <= n; ++i)
		for (int j = 6 * i; j >= i; --j) {
			double sum = 0;
			for (int k = 1; k <= 6 && j - k >= i - 1; ++k)
				//��Ҫע����ǣ�i - 1���ڵ����ݲ����ڵ�n - 1��Ͷ������Ҫ�����˵�
				sum += res[j - k] * 1.0 / 6;
			res[j] = sum;
		}
	vector<pair<int, double> > ans(5 * n + 1, make_pair(0, 0));
	for (int i = 0; i < ans.size(); ++i)
		ans[i] = make_pair(n + i, res[n + i]);
	return ans;
}