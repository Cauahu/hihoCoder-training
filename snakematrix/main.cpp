#include <iostream>

using namespace std;

int main()
{
    int N = 5;
    int A[1000][100] = {0};
    int i = 0,j = 0,m = 1;
    int a = 0,b = N;
    do
    {
        //��ͷ����ǽ��ʱ���䣬ֱ������λ�ã���νǽ��Ҫô���ǵ���N�ģ�Ҫô������Χ�Ѿ���Ԫ���ˡ�

        while(j<N&&A[i][j]==0)
        {
            A[i][j] = m++;
            j++;
        }
        j--;
        i++;
        while(i<N&&A[i][j]==0)
        {
            A[i][j] = m++;
            i++;
        }
        i--;
        j--;
        while(j>-1&&A[i][j]==0)
        {
            A[i][j] = m++;
            j--;
        }
        j++;
        i--;
        while(i>-1&&A[i][j]==0)
        {
            A[i][j] = m++;
            i--;
        }
        i++;
        j++;

    }while(i!=j||i!=N/2);
    A[i][j] = m;//������������Ԫ��
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            cout << A[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
