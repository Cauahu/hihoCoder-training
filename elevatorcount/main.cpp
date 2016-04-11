/*
题目：编程之美1.8 小飞的电梯调度算法
*/

#include <iostream>

using namespace std;

void solution_one(int *a, int N)//一层一层的计算，时间复杂度为O(n^2)
{
    int sumfloor, tarfloor = -1, minsumfloor;
    for(int i=1;i<=N;i++)
    {
        sumfloor = 0;
        for(int j=1;j<i;j++)
            sumfloor += a[j]*(i-j);
        for(int j=i+1;j<=N;j++)
            sumfloor += a[j]*(j-i);
        cout << " tarfloor:" << i << " minfloor:" << sumfloor << endl;
        if(tarfloor == -1 || sumfloor < minsumfloor)
        {
            minsumfloor = sumfloor;
            tarfloor = i;
        }
    }

    cout << "solution_one tarfloor:" << tarfloor << " minfloor:" << minsumfloor << endl;
}

void solution_two(int *a, int N)//迭代，时间复杂度为O(n)
{
    int N1=0,N2=a[1],N3=0;//分别表示第i-1层，第i层，第i+1层的人数。minfloor=Min(Y+N1+N2-N3, Y),Y表示第i层要爬的楼梯数。
    int minfloor=0, tarfloor=1;
    for(int i=2;i<=N;i++)
    {
        N3 += a[i];
        minfloor += a[i]*(i-1);
    }
    for(int i=2;i<=N;i++)
    {
        if(N1+N2 < N3)
        {
            tarfloor = i;
            minfloor += (N1+N2-N3);
            N1 += a[i-1];
            N2 = a[i];
            N3 -= a[i];

        }
        else
            break;
    }
    cout << "solution_two tarfloor:" << tarfloor << " minfloor:" << minfloor << endl;

}

int main()
{
    int a[] = {0,2,3,4,1,2,1};
    solution_one(a, 6);
    solution_two(a, 6);
    return 0;
}
