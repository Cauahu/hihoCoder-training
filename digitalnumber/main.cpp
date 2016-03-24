#include <iostream>
#include <stdio.h>


using namespace std;

int DGNM[10] = {0x77,0x12,0x5D,0x5B,0x3A,0x6B,0x6F,0x52,0x7F,0x7B};//每个LED数码管表示的0-9数字的每一位排列的十六进制表示。

int bin2dec(int * a)//将二进制转化为10进制。
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

bool juge(int a,int b)//判断b的数码管排列是否包含a的形式
{
    for(int i=0;i<7;i++)
    {
        if((a%2)==1&&(b%2)==0)//a中为1的位，在b中也要为1
            return false;
        a /=2;
        b /=2;
    }
    return true;

}

void DFS(int * dig,int cur,int sum,int N,int &flag,int l)
{
    if(cur == -1)//终止条件：一种排列完成。
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
                sum -=i*l;//还原sum，否则会出现溢出情况。

            }

        }
    }
}

void Turnover(int K,int N)//主函数：处理输入格式
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
