#include <iostream>

using namespace std;

struct BTreeNode
{
	int value;
	BTreeNode* leftNode;
	BTreeNode* rightNode;
};

void mirrorTree(BTreeNode* pNode)
{
	if(pNode == NULL)
		return;
	if(pNode->leftNode == NULL && pNode->rightNode == NULL)
		return;
	BTreeNode* tempNode = pNode->leftNode;
	pNode->leftNode = pNode->rightNode;
	pNode->rightNode = tempNode;
	if(pNode->leftNode)
		mirrorTree(pNode->leftNode);
	if(pNode->rightNode)
		mirrorTree(pNode->rightNode);
}

BTreeNode* buildTree(int *a, int &k, int n)
{
	if(k < n)
	{
		if(a[k] == 0)
		{
			k++;
			return NULL;
		}
		BTreeNode* p = new BTreeNode;
		p->value = a[k++];
		p->leftNode = buildTree(a, k, n);
		p->rightNode = buildTree(a, k, n);
		return p;
	}
}

void preoder(BTreeNode* p)
{
	if(p != NULL)
	{
		cout << p->value;
		preoder(p->leftNode);
		preoder(p->rightNode);
	}
	else
		cout << 0;
}

int main()
{
	int a[] = {8,8,9,0,0,2,4,0,0,7,0,0,7,0,0};
	int k = 0;
	BTreeNode* pTree = buildTree(a, k, 15);
	mirrorTree(pTree);
	preoder(pTree);
	
}


