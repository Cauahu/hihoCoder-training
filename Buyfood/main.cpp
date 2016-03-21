#include <iostream>

using namespace std;

int ASP = 0, N;
int pri[55], asps[55];

void DFS(int cur, int sum, int asp, int n)
{
    if(sum && sum%50 == 0 && n <= 3)//�ж������Ƿ����
    {
        if(asp > ASP)
            ASP =asp;
    }
    if(n > 3 || cur ==N)//�ݹ���ֹ����
        return;
    DFS(cur+1, sum, asp, n);//�������cur��ʳƷ
    DFS(cur+1, sum+pri[cur], asp+asps[cur], n+1);//�����cur��ʳƷ
}



int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        double a;
        cin >> a >> asps[i];
        pri[i] = static_cast<int>(a*10);
    }
    DFS(0,0,0,0);
    cout << ASP << endl;

    return 0;
}
