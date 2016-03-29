#include <iostream>

using namespace std;

int N = 2, M = 2 ,K = 10;

void findxy()
{
    int i = 1, j = 1;
    int a = N,b = M;
    while(1)
    {
        while(1)
        {
            int k = i, m = j,sum = 0;
            cout << i << j << endl;
            while(a--)
            {
                while(b--)
                {
                    if(m>=k)
                        sum += k;
                    else
                        sum +=m;
                    m++;
                }
                k++;
                m = j;
                cout << k << " " << m;
            }
            cout << sum << endl;
            if(sum%K==0)
            {
                cout << "x:" << i << " y:" << j << endl;
                return ;
            }
            i++;
            j++;
        }
    }
}

int main()
{

    //cin >> N >> M >> K;
    //cout << N << M << K;
    findxy();

    return 0;
}
