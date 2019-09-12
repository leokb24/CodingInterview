/*
37：序列化二叉树
题目：请实现两个函数，分别用来序列化和反序列化二叉树。
*/

#include "Tree.h"
#include <sstream>
#include <string>
using namespace std;

void serialize(TreeNode *pRoot, ostringstream &out) {
	if (pRoot) {
		out << pRoot->val << " ";
		serialize(pRoot->left, out);
		serialize(pRoot->right, out);
	}
	else {
		out << "# ";
	}
}

string serialize(TreeNode *pRoot) {
	ostringstream out;
	serialize(pRoot, out);
	return out.str();
}

TreeNode *deserialize(istringstream &in) {
	string val;
	in >> val;
	if (val == "#") return nullptr;
	TreeNode *pRoot = new TreeNode(stoi(val));
	pRoot->left = deserialize(in);
	pRoot->right = deserialize(in);
	return pRoot;
}

TreeNode *deserialize(string data) {
	istringstream in(data);
	return deserialize(in);
}