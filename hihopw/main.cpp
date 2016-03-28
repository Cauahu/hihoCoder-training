#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int *a = new int(N);
    int n = 0;
    while(n < N)
        cin >>  a[n++];
    for(n=1;n<N;n++)
    {
        if(a[n-1]>a[n])
            break;
    }
    if(n==N)
        cout << a[0] ;
    else
    {
        for(int i=0;i<n;i++)
        {
            cout << a[i] << " ";
        }
    }

    return 0;
}
