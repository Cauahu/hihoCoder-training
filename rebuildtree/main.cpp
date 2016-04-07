#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

/*
题目：根据二叉树的先序和中序遍历，来重建二叉树，然后输出后续遍历。
解：
    题目的关键在于如何根据先序和中序遍历来重建二叉树。可以先序遍历的第一个元素为根节点，在中序遍历中找到这个根节点，
    从而可以将中序遍历分为左右两个部分，左边部分为左子树的中序遍历，右边部分为右子树的中序遍历，
    进而也可以将先序遍历除第一个元素以外的剩余部分分为两个部分，第一个部分为左子树的先序遍历，第二个部分为右子树的先序遍历。
    由上述分析结果，可以递归调用构建函数，根据左子树、右子树的先序、中序遍历重建左、右子树。
*/
    char preorder[] = {'A','B','C','D','E','F','G','H'};
    char inorder[] = {'B','D','C','E','A','F','H','G'};

//建树的解法
typedef struct Node
{
    char vaule;
    Node * lchild;
    Node * rchild;
} TNode,*PTNode;


PTNode rebuildtree(char * preorder, int pfirst, int pend , char * inorder, int ifirst, int iend)
{
    if(pfirst > pend) return NULL;//递归结束条件
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
    node->lchild = rebuildtree(preorder, pfirst+1, pfirst+fnum, inorder, ifirst, cur-1);//构建左子树
    node->rchild = rebuildtree(preorder, pfirst+fnum+1, pend, inorder, cur+1, iend);//构建右子树
    return node;
}

void postorder(PTNode node)//后序遍历
{
    if(node->lchild != NULL)
        postorder(node->lchild);
    if(node->rchild != NULL)
        postorder(node->rchild);
    cout << node->vaule << " ";
}


//不建树的解法：用数组存储先序遍历中每个元素在中序遍历中的位置，设置游标cur遍历先序序列，模拟后序遍历行为即可。
int a[8], cur=-1;//cur用来遍历先序序列中的元素
void pretreatment()
{
    memset(a,-1,8*sizeof(int));
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(preorder[i] == inorder[j])
                a[i] = j;               //存储先序遍历中的每个元素在中序遍历中的位置。
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
