#include <iostream>

using namespace std;

int package_01(int W[], int V[], int N, int C)
{
    /*
    01��������M����Ʒȡ�����ɼ����ڿռ�ΪW�ı����ÿ����Ʒ�����ΪC1��C2��C3��......��Cn����Ӧ�ļ�ֵΪW1��W2��......Wn��
    ��������ı����Ƕ�̬�滮��DP��
    F[i][j]��ʾǰi����Ʒ��ѡȡ���ɼ�����ռ�Ϊj�ı��������ܵõ�������ֵ
    F[i][j]=max( F[i-1][j] , F[i-1][j-W[i]]+V[i]) ������W[i]��i����Ʒ�������V[i]�ǵ�i����Ʒ�ļ�ֵ
    ʱ�估�ռ临�ӶȾ�ΪO(VN)
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
            if(j >= W[i-1] && F[i][j] < F[i-1][j-W[i-1]]+V[i-1])//ע��i-1���߼��ϵ�ֵ�������Ӧ
                F[i][j] = F[i-1][j-W[i-1]]+V[i-1];//ע��i-1���߼��ϵ�ֵ�������Ӧ
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

