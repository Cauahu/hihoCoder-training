#include <iostream>
#include <string.h>
using namespace std;
/*
����Ӿ������⣬ͨ���ֽ�Ϊ����Ӷ�������⣬������Ӷ���������ö�̬�滮�����
*/

int a[][3] = {{4,-2,9},{-1,3,8},{-6,7,6},{0,9,-5}};

int maxsubsum(int *A,int &y1,int &y2)
{
    //��̬�滮��,״̬ת�Ʒ��̣�b[j]=max{b[j-1]+a[j],a[j]},1<=j<=n��
    int b = -9999999, sum = -9999999;
    int j = 0, k = 0;//j��k�ֱ��¼��Χ����
    for(int i=0;i<5;i++)
    {
        if(b+A[i] > A[i])
        {
            j = i;
            b += A[i];
        }
        else
        {
            j = i;
            k = i;
            b = A[i];
        }
        if(b > sum )
        {
            sum = b;
            y1 = k;
            y2 = j;
        }

    }
    return sum;
}

int maxmatrixsum()
{
    int x1, y1, x2, y2;
    int sum = -9999999;
    for(int i=0;i<4;i++)
    {
        int b[4] = {-999999,-999999,-999999,-999999};//��¼j��k�����к�
        for(int j=i;i<4;j++)
        {
            for(int k=0;k<3;k++)
            {
                b[k] +=a[j][k];//��ʱ��¼k�еĺ�
            }
            int y1_t,y2_t;
            int temp = maxsubsum(b,y1_t,y2_t);
            if(temp > sum)
            {
                sum = temp;
                x1 = i;
                x2 = j;
                y1 = y1_t;
                y2 = y2_t;
            }
        }
    }
    for(int i=x1;i<=x2;i++)
    {
        for(int j=y1;j<=y2;j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return sum;
}



int main()
{
    maxmatrixsum();
    return 0;
}
