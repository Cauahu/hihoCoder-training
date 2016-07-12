#include <iostream>

using namespace std;

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool issubtree(TreeNode *A, TreeNode* B)
{
	if(A == NULL && B == NULL) return true;
	if(A == NULL && B != NULL) return false;
	if(A->val != B->val) return false;
	return issubtree(A->left, B->left) && issubtree(A->right, B->right);
}


bool chkIdentical(TreeNode *A, TreeNode* B)
{
	if(A == NULL && B == NULL)
		return true;
	if(A == NULL || B == NULL)
		return false;
	if(issubtree(A, B))
		return true;
	return chkIdentical(A->left, B) || chkIdentical(A->right,B) ;

}


int main()
{
	return 0;
}
