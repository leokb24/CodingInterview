/*
31 栈的压入、弹出序列 leetcode 946
题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
4、3、5、1、2就不可能是该压栈序列的弹出序列。
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
