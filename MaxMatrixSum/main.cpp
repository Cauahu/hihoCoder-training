#include <iostream>
#include <string.h>
using namespace std;
/*
����Ӿ������⣬ͨ���ֽ�Ϊ����Ӷ�������⣬������Ӷ���������ö�̬�滮�����
*/

int a[][4] = {{0,-2,-7,0},{9,2,-6,2},{-4,1,-4,1},{-1,8,0,-2}};

int maxsubsum(int *A,int &c,int &d)
{
    //��̬�滮��,״̬ת�Ʒ��̣�b[j]=max{b[j-1]+a[j],a[j]},1<=j<=n��
    int b = A[0], sum = A[0];
    int p = 0,q = 0;
    for(int i=1;i<4;i++)
    {
        if(b+A[i] > A[i])
        {
            q = i;
            b += A[i];
        }
        else
        {
            p = q = i;
            b = A[i];
        }
        if(b > sum )
        {
            c = p;
            d = q;
            sum = b;
        }

    }
    return sum;
}

int maxmatrixsum()
{
    int x1, y1, x2, y2;//��¼�Ӿ���Χ
    int sum = -9999999;
    for(int i=0;i<4;i++)
    {
        int b[4] = {0};//��¼j��k�����к�
        for(int j=i;j<4;j++)
        {
            int k;
            for(k=0;k<4;k++)
            {
                b[k] +=a[j][k];//��ʱ��¼k�еĺ�
            }
            int c = -1,d = -1;
            int temp = maxsubsum(b,c,d);
            if(temp > sum)
            {
                x1 = i;
                y1 = c;
                x2 = j;
                y2 = d;
                sum = temp;
            }
        }
    }
    for(int i=x1;i<=x2;i++)
    {
        for(int j=y1;j<=y2;j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
    return sum;
}

int main()
{
    cout << maxmatrixsum();
    return 0;
}
