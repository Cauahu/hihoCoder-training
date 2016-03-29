#include <iostream>
#include <cstring>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[1005][1005];
int A[1005];
int const INF = 0x3fffffff;

int main()
{
    int N,M,S,T;
    cin >> N >> M >> S >> T;
    //memset(dp,INF,sizeof(dp));
    for(int i=1;i<=N;i++)
        cin >> A[i];
    for(int i=0;i<=N;i++)
        for(int j=0;j<=M;j++)
            dp[i][j] = INF;
    dp[0][0] = 0;
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=M;j++)
        {
            int c = A[i]/S+(A[i]%S!=0); //过第i关所需的答题正确数为c，答题不正确数为w。
            for(;c>=0;c--)
            {
                int w = 0;
                if((A[i]-c*S)>0)
                {
                    int temp = A[i]-c*S;
                    w = temp/T+(temp%T!=0);
                }
                if(j>c+w&&dp[i-1][j-c-w]<INF)
                    dp[i][j] = min(dp[i][j],dp[i-1][j-c-w]+c);
            }
        }
    }
    int ans = INF;
    for(int i=0;i<=M;i++)
        ans = min(ans, dp[N][i]);
    cout << ans << endl;

    return 0;
}
