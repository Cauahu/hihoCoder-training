/*
��Ŀ�����֮��1.8 С�ɵĵ��ݵ����㷨
*/

#include <iostream>

using namespace std;

void solution_one(int *a, int N)//һ��һ��ļ��㣬ʱ�临�Ӷ�ΪO(n^2)
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

void solution_two(int *a, int N)//������ʱ�临�Ӷ�ΪO(n)
{
    int N1=0,N2=a[1],N3=0;//�ֱ��ʾ��i-1�㣬��i�㣬��i+1���������minfloor=Min(Y+N1+N2-N3, Y),Y��ʾ��i��Ҫ����¥������
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
