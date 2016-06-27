#include <stdio.h>
#include <iostream>
using namespace std;
//模拟循环链表。
int main ()
{
    int i, n, next[1000], q, p;
    while( ~scanf( "%d", &n ) ){
        for( i = 0, n --; i < n; i ++ ) next[i] = i + 1;
        next[n] = 0;
    for( i = 0; i < n; i ++ ) 
        cout << next[i] << " ";
        i = 0;
        cout << "\np\tq\ti\t\n" ;
        while( n -- ){
            p = next[i], q = next[next[p]];
            next[p] = q;
            i = q;
            cout << p << "\t" << q << "\t" << i  << "\t" << next[p] << "\n" ;
            for( int j = 0; j < n; ++j ) 
                    cout << next[j] << " ";
            cout << endl;
        }
        printf( "%d\n", i );
    }
    return 0;
}