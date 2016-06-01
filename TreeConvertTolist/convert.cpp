#include <iostream>
using namespace std;
struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

TreeNode* insert(TreeNode* root, int x){
	TreeNode* p = new TreeNode;
	p->val = x;
	p->left = NULL;
	p->right = NULL;
	if(root == NULL)
		root = p;
	else if(x < root->val)
		root->left = insert(root->left,x);
	else
		root->right = insert(root->right,x);
	return root;
}

TreeNode* CreateNode(int value[], int n){
	TreeNode* root = NULL;
	int i = 0;
	while(i < n){
		root = insert(root,value[i]);
		i++;
	}
	return root;
}

void inorder(TreeNode* root){
	if(!root)
		return;
	else{
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
}

void listorder(TreeNode* root){
	while(!root){
		cout << root->val << " ";
		root = root->right;
	}
}

TreeNode * Convert(TreeNode* root){
	if(root == NULL)
		return NULL;
	if(root->left){
		TreeNode* p = Convert(root->left);
		while(p && p->right)
			p = p->right;
		if(p) p->right = root;
		root->left = p;
	}
	if(root->right){
		TreeNode* p = Convert(p->right);
		while(p && p->left)
			p = p->left;
		if(p) p->left = root;
		root->right = p;
	}
	return root;
}

int main(){
	int value[] = {8,3,10,1,6,14,4,7,13};
	TreeNode* root = CreateNode(value, 9), *pHead = NULL;
	inorder(root);
	cout << endl;
	pHead = Convert(root);
	//while(pHead != NULL && pHead != NULL)
	//	pHead = pHead->left;
	//listorder(pHead);
	cout << endl;
	return 0;
}
