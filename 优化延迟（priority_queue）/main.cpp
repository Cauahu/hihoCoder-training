#include <iostream>
#include <queue>
using namespace std;

int N,Q;//N是数据量大小，Q是阈值。
int inp[1000],test[1000];
priority_queue<int> kq;

bool checkqueue(int size)
{
    int cur=0;
    for(int i=0;i<N;i++)//将inp数组按题目要求处理
    {
        if(kq.size()==static_cast<unsigned>(size)&&!kq.empty())//当队列满时，取出最大权值数
        {
            test[cur++]=kq.top();
            kq.pop();
        }
        kq.push(inp[i]);//向队列中添加元素
    }
    while(!kq.empty())//将队列剩余元素清空
    {
        test[cur++]=kq.top();
        kq.pop();
    }
    int res=0;
    for(int i=0;i<N;i++)
    {
        res += (i+1)*test[i];//统计结果
    }
    return res<=Q;
}



int main()
{
    cin >> N >> Q;
    for(int i=0;i<N;i++)
    {
        cin >> inp[i];
    }
    for(int i=2;i<=N;i++)
    {
        if(checkqueue(i))
        {
            cout << i << endl;
            break;
        }

    }
    return 0;
}
