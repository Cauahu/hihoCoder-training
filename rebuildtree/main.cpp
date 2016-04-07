#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

/*
��Ŀ�����ݶ������������������������ؽ���������Ȼ���������������
�⣺
    ��Ŀ�Ĺؼ�������θ������������������ؽ���������������������ĵ�һ��Ԫ��Ϊ���ڵ㣬������������ҵ�������ڵ㣬
    �Ӷ����Խ����������Ϊ�����������֣���߲���Ϊ������������������ұ߲���Ϊ�����������������
    ����Ҳ���Խ������������һ��Ԫ�������ʣ�ಿ�ַ�Ϊ�������֣���һ������Ϊ������������������ڶ�������Ϊ�����������������
    ������������������Եݹ���ù�����������������������������������������ؽ�����������
*/
    char preorder[] = {'A','B','C','D','E','F','G','H'};
    char inorder[] = {'B','D','C','E','A','F','H','G'};

//�����Ľⷨ
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


//�������Ľⷨ��������洢���������ÿ��Ԫ������������е�λ�ã������α�cur�����������У�ģ����������Ϊ���ɡ�
int a[8], cur=-1;//cur�����������������е�Ԫ��
void pretreatment()
{
    memset(a,-1,8*sizeof(int));
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(preorder[i] == inorder[j])
                a[i] = j;               //�洢��������е�ÿ��Ԫ������������е�λ�á�
        }
    }
}
void usearrysovle(char * inorder, int l, int r)
{
    if(l > r)
        return ;
    if(l < r)
        cur++;
    int n=a[cur];
    if(l == r)
    {
        cout << inorder[r] << " ";
        cur++;
        return ;
    }
    cout << "l:" << l << " r:" << r << " n:" << n << " cur:" << cur << endl;
    usearrysovle(inorder, l, n-1);
    usearrysovle(inorder, n+1, r);
    cout << inorder[n] << " ";
}

int main()
{
    //PTNode node = rebuildtree(preorder,0,7,inorder,0,7);
    //postorder(node);
    pretreatment();
    usearrysovle(inorder,0,7);
    return 0;
}
