/*
8 二叉树的下一个结点
题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。
*/

struct TreeNode {
	int val;
	TreeNode *left, *right, *parent;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
};

TreeNode *getNext(TreeNode *root) {
	if (!root) return nullptr;

	TreeNode *pNode = root, *pNext = nullptr;
	if (pNode->right) {
		pNode = pNode->right;
		while (pNode->left)
			pNode = pNode->left;
		pNext = pNode;
	}
	else if (pNode->parent) {
		TreeNode *pParent = pNode->parent;
		while (pParent && pNode == pParent->right) {
			pNode = pParent;
			pParent = pNode->parent;
		}
		pNext = pNode;
	}
	return pNext;
}
