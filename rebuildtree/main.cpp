#include <iostream>
#include <stdlib.h>
using namespace std;

/*
��Ŀ�����ݶ������������������������ؽ���������Ȼ���������������
�⣺
    ��Ŀ�Ĺؼ�������θ������������������ؽ���������������������ĵ�һ��Ԫ��Ϊ���ڵ㣬������������ҵ�������ڵ㣬
    �Ӷ����Խ����������Ϊ�����������֣���߲���Ϊ������������������ұ߲���Ϊ�����������������
    ����Ҳ���Խ������������һ��Ԫ�������ʣ�ಿ�ַ�Ϊ�������֣���һ������Ϊ������������������ڶ�������Ϊ�����������������
    ������������������Եݹ���ù�����������������������������������������ؽ�����������
*/


typedef struct Node
{
    char vaule;
    Node * lchild;
    Node * rchild;
} TNode,*PTNode;


PTNode rebuildtree(char * preorder, int pfirst, int pend , char * inorder, int ifirst, int iend)
{
    if(pfirst > pend) return NULL;//�ݹ��������
    PTNode node = new TNode;
    node->vaule = preorder[pfirst];
    node->lchild = NULL;
    node->rchild = NULL;
    if(pfirst == pend)
        return node;
    int fnum = 0, cur = ifirst;
    while(preorder[pfirst] != inorder[cur])
    {
        fnum++;
        cur++;
    }
    node->lchild = rebuildtree(preorder, pfirst+1, pfirst+fnum, inorder, ifirst, cur-1);//����������
    node->rchild = rebuildtree(preorder, pfirst+fnum+1, pend, inorder, cur+1, iend);//����������
    return node;
}

void postorder(PTNode node)//�������
{
    if(node->lchild != NULL)
        postorder(node->lchild);
    if(node->rchild != NULL)
        postorder(node->rchild);
    cout << node->vaule << " ";
}
int main()
{
    char preorder[] = {'A','B','C','D','E','F','G','H'};
    char inorder[] = {'B','D','C','E','A','F','H','G'};
    PTNode node = rebuildtree(preorder,0,7,inorder,0,7);
    postorder(node);
    return 0;
}
