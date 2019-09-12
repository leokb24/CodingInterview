/*
31 ջ��ѹ�롢�������� leetcode 946
��Ŀ�����������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ���������
��Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ���������1��2��3��4��
5��ĳջ��ѹջ���У�����4��5��3��2��1�Ǹ�ѹջ���ж�Ӧ��һ���������У���
4��3��5��1��2�Ͳ������Ǹ�ѹջ���еĵ������С�
*/

#include <stack>
#include <vector>

using namespace std;

bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
	stack<int> st;
	int popIndex = 0, pushIndex = 0;

	while (popIndex < popped.size()) {
		while (st.empty() || st.top() != popped[popIndex]) {
			if (pushIndex >= pushed.size()) break;
			st.push(pushed[pushIndex++]);
		}
		if (st.top() != popped[popIndex]) break;
		st.pop();
		popIndex++;
	}
	return st.empty() && popIndex == popped.size();
}
