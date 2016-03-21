#include <iostream>

using namespace std;

int package_01(int W[], int V[], int N, int C)
{
    /*
    01背包是在M件物品取出若干件放在空间为W的背包里，每件物品的体积为C1，C2，C3，......，Cn，对应的价值为W1，W2，......Wn。
    背包问题的本质是动态规划（DP）
    F[i][j]表示前i件物品中选取若干件放入空间为j的背包中所能得到的最大价值
    F[i][j]=max( F[i-1][j] , F[i-1][j-W[i]]+V[i]) ，其中W[i]是i件物品的体积，V[i]是第i件物品的价值
    时间及空间复杂度均为O(VN)
    */
    int F[7][11];
    for(int i=0;i<=N;i++)
        F[i][0] = 0;
    for(int i=0;i<=C;i++)
        F[0][i] = 0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=C;j++)
        {
            F[i][j] = F[i-1][j];
            if(j >= W[i-1] && F[i][j] < F[i-1][j-W[i-1]]+V[i-1])//注意i-1是逻辑上的值和数组对应
                F[i][j] = F[i-1][j-W[i-1]]+V[i-1];//注意i-1是逻辑上的值和数组对应
        }
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=C;j++)
        {
            cout << F[i][j] << " ";
        }
        cout << endl;
    }

    return F[N][C];
}


int package_02(int W[], int V[], int N, int C)
{
    int F[11] = {0};
    for(int i=0;i<N;i++)
    {
        for(int j=C;j>=W[i];j--)
        {
            if(F[j] < F[j-W[i]]+V[i])
                F[j] = F[j-W[i]]+V[i];
        }
    }
    for(int j=0;j<=C;j++)
    {
        cout << F[j] << " ";
    }
    return F[10];
}


int main()
{
    int W[] = {2,3,1,4,6,5};
    int V[] = {5,6,5,1,19,7};
    cout << "max value : " << package_02(W,V,6,10) << endl;
    return 0;
}

