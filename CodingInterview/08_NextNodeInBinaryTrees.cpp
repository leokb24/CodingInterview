/*
8 ����������һ�����
��Ŀ������һ�ö����������е�һ����㣬����ҳ��������˳�����һ����㣿
���еĽ������������ֱ�ָ�������ӽ���ָ�����⣬����һ��ָ�򸸽���ָ�롣
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
