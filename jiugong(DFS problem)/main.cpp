#include <iostream>
#include <string.h>
using namespace std;

int inp[10],test[10],res[10],used[10];
int flag = 0;

bool check()
{
    int i,sum;
    for(i=0;i<3;i++)//测试行是否符合
    {
        sum = test[i*3+1]+test[i*3+2]+test[i*3+3];
        if(sum!=15)
            return false;
    }
    for(i=1;i<=3;i++)//测试列是否符合
    {
        sum = test[i]+test[i+3]+test[i+6];
        if(sum!=15)
            return false;
    }
    {//测试正斜方
        sum = test[1]+test[5]+test[9];
        if(sum!=15)
            return false;
    }
    {//测试反斜方
        sum = test[3]+test[5]+test[7];
        if(sum!=15)
            return false;
    }
    return true;
}


void DFS(int cur)
{
    if(10 == cur&&check())
    {
        for(int i=0;i<=9;i++)
            res[i]=test[i];
        flag++;
    }
    else
    {
        if(inp[cur])
        {
            test[cur]=inp[cur];
            DFS(cur+1);
        }
        else
        {
            for(int i=1;i<=9;i++)
            {
                if(!used[i])
                {
                    test[cur]=i;
                    used[i]=1;
                    DFS(cur+1);
                    used[i]=0;
                }
            }
        }
    }
}

int main()
{
    int a[10] = {0,0,7,2,0,5,0,0,3,0};
    memcpy(inp,a,sizeof(a));
    DFS(1);
    if(flag == 1)
    {
        for(int i=1;i<10;i++)
        {
            cout << res[i];
            if(i%3==0)
                cout << endl;
        }
    }
    else if(flag > 1)
        cout << "too many" << endl;
    return 0;
}
