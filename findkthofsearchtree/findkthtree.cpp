#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
};

void preorder(TreeNode* pRoot, vector<TreeNode*> &vec)
{
	if(pRoot == NULL)
		return;
	preorder(pRoot->left, vec);
	vec.push_back(pRoot);
	preorder(pRoot->right, vec);
}

TreeNode* kthnode(TreeNode* pRoot, int k)
{
	if (pRoot == NULL || k < 1)
	{
		return NULL;
	}

	vector<TreeNode*> vec;
	preorder(pRoot, vec);
	if (k > vec.size())
	{
		/* code */
		return NULL;
	}
	return vec[k-1];
}