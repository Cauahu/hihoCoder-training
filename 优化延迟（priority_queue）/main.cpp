#include <iostream>
#include <queue>
using namespace std;

int N,Q;//N是数据量大小，Q是阈值。
int inp[1000],test[1000];
priority_queue<int> kq;

bool checkqueue(int size)
{
    int cur=0;
    for(int i=0;i<N;i++)
    {
        if(kq.size()==static_cast<unsigned>(size)&&!kq.empty())
        {
            test[cur++]=kq.top();
            kq.pop();
        }
        kq.push(inp[i]);
    }
    while(!kq.empty())
    {
        test[cur++]=kq.top();
        kq.pop();
    }
    int res=0;
    for(int i=0;i<N;i++)
    {
        res += (i+1)*test[i];
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
