/*
64：求1+2+…+n
题目：求1+2+…+n，要求不能使用乘除法、for、while、if、else、switch、case
等关键字及条件判断语句（A?B:C）。
*/

int sumSolution(int n) {
	int ans = n;
	ans && (ans += sumSolution(n - 1));
	return ans;
}