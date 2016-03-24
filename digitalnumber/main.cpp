#include <iostream>
#include <stdio.h>


using namespace std;

int DGNM[10] = {0x77,0x12,0x5D,0x5B,0x3A,0x6B,0x6F,0x52,0x7F,0x7B};//ÿ��LED����ܱ�ʾ��0-9���ֵ�ÿһλ���е�ʮ�����Ʊ�ʾ��

int bin2dec(int * a)//��������ת��Ϊ10���ơ�
{
    int t=1,sum=0;
    for(int i=7;i>-1;i--)
    {
        if(a[i]!=0)
            sum+=a[i]*t;
        t*=2;
    }
    return sum;
}

bool juge(int a,int b)//�ж�b������������Ƿ����a����ʽ
{
    for(int i=0;i<7;i++)
    {
        if((a%2)==1&&(b%2)==0)//a��Ϊ1��λ����b��ҲҪΪ1
            return false;
        a /=2;
        b /=2;
    }
    return true;

}

void DFS(int * dig,int cur,int sum,int N,int &flag,int l)
{
    if(cur == -1)//��ֹ������һ��������ɡ�
    {
        if(sum < N)
        {
            flag++;
        }
    }
    else
    {
        for(int i=0;i<10;i++)
        {
            if(juge(dig[cur],DGNM[i]))
            {
                sum +=i*l;
                l *=10;
                cout << dig[cur] << " " << sum << endl;
                DFS(dig,cur-1,sum,N,flag,l);
                l /=10;
                sum -=i*l;//��ԭsum������������������

            }

        }
    }
}

void Turnover(int K,int N)//�����������������ʽ
{
    int temp[5][7] = {0};
    int dig[5] = {0};
    for(int i=0;i<K;i++)
    {
        char a;
        while((a=getchar())!='\n')
        {
            if(a!=' ')
                temp[i][a-'0'] = 1;
        }
        dig[i] = bin2dec(temp[i]);
    }
    int flag=0;
    DFS(dig,K-1,0,N,flag,1);
    cout << flag << endl;

}

int main()
{

    Turnover(1,1);
    return 0;
}
