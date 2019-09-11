#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<int> getNext(string p) {
	int j = 0, k = -1;
	vector<int> next(p.size());
	next[0] = -1;

	while (j < p.size() - 1) {
		if (k == -1 || p[k] == p[j]) {
			k++;
			j++;
			next[j] = k;
		}
		else
			k = next[k];
	}
	return next;
}

int kmpSearch(string s, string p, vector<int> next) {
	int i = 0, j = 0;
	int sLen = s.size(), pLen = p.size();

	while (i < sLen && j < pLen) {
		if (j == -1 || p[j] == s[i]) {
			i++;
			j++;
		}
		else
			j = next[j];
	}

	if (j == pLen)
		return i - j;
	else
		return -1;
}
