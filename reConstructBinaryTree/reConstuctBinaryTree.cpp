#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
};


struct TreeNode* reConstructBinaryTree_(vector<int> pre,int pb, int pe, vector<int> in, int ib, int ie){
	if(pb > pe) return NULL;
	struct TreeNode *node = new TreeNode;
	node->val = pre[pb];
	node->left = node->right = NULL;
	int len = 0;
	while(pre[pb] != in[ib+len])
		len++;
	node->left = reConstructBinaryTree_(pre, pb+1, pb+len, in, ib, ib+len-1);
	node->right = reConstructBinaryTree_(pre, pb+len+1, pe, in, ib+len+1, ie);
	return node;
}

struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
	struct TreeNode * node = reConstructBinaryTree_(pre, 0, pre.size()-1, in, 0, in.size()-1);
	return node;
}


void postOrderPrint(struct TreeNode* root){

	if(root->left != NULL)
		postOrderPrint(root->left);
	if(root->right != NULL)
		postOrderPrint(root->right);
	cout << root->val << " ";

}

int main(){
	int p[] = {1,2,4,7,3,5,6,8}, i[] = {4,7,2,1,5,3,8,6};
	vector<int> pre(p, p+8), in(i, i+8);
	struct TreeNode* root = reConstructBinaryTree(pre, in);
	postOrderPrint(root);	
	cout << endl;
	return 0;
}
