#include <iostream>

using namespace std;

struct BTreeNode{
	int value;
	BTreeNode* leftTree;
	BTreeNode* rightTree;
};

bool doesTree1haveTree2(BTreeNode* pTree1, BTreeNode* pTree2)
{
	if(pTree2 == NULL)
		return true;
	if(pTree1 == NULL)
		return false;
	if(pTree1->value != pTree2->value)
		return false;
	return doesTree1haveTree2(pTree1->leftTree, pTree2->leftTree) && doesTree1haveTree2(pTree1->rightTree, pTree2->rightTree) ;
}

bool isSubTree(BTreeNode* pTree1, BTreeNode* pTree2 )
{
	bool result = false;
	if(pTree1 != NULL && pTree2 != NULL)
	{
		if(pTree1->value == pTree2->value )
			result = doesTree1haveTree2(pTree1, pTree2);
		if(!result)
			result = isSubTree(pTree1->leftTree, pTree2);
		if(!result)
			result = isSubTree(pTree1->rightTree,pTree2);
	}
	return result;
}

void preorder(BTreeNode* p)
{
	if(p!=NULL)
	{
		cout << p->value;
		preorder(p->leftTree);
		preorder(p->rightTree);
	}
	else
		cout << 0;
}

BTreeNode* buildTree(int *a, int &k, int n)
{
	if(k < n){

		if(a[k] == 0)
		{
			k++;
			return NULL;
		}
		BTreeNode* p = new BTreeNode;
		p->value = a[k++];
		p->leftTree = buildTree(a, k, n);
		p->rightTree = buildTree(a, k, n);
		return p;
	}
}

int main()
{
	int a[] = {8,8,9,0,0,2,4,0,0,7,0,0,7,0,0};
	int b[] = {8,9,0,0,2,0,0};
	int k = 0;
	BTreeNode* pTree1 = buildTree(a, k, 15);
	preorder(pTree1);
	cout << endl;
	k = 0;
	BTreeNode* pTree2 = buildTree(b, k, 7);
	preorder(pTree2);
	cout << endl;
	
	if(isSubTree(pTree1, pTree2))
		cout << "pTree2 is pTree1's subtree" << endl;
	else
		cout << "pTree2 is not pTree1's subtree" << endl;
}
