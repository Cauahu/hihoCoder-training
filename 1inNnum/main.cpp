/*

问题：给定一个十进制的正整数N，写下从1开始到N的所有整数，然后数一下其中出现的所有“1”的个数。
假设N=abcde，这里abcde分别是十进制数N的各个数位上的数字。例如我们计算百位上出现1的次数，它将会受到三个因素的影响：百位上的数字，
百位一下，百位以上的数字。

*/

#include <iostream>

using namespace std;

void countonenum(int N)
{
    int icount = 0;
    int ifactor = 1;
    int ilow = 0;
    int icur = 0;
    int ihig = 0;
    while(n / ifactor != 0)
    {
        ilow = n-(n/ifactor)*ifactor;
        icur = (n/ifactor)%10;
        ihig = n/(ifactor*10);
        switch(icur)
        {
        case 0:
            icount += ihig*ifactor;
            break;
        case 1:
            icount += ihig*ifactor + ilow + 1;
        default:
            icount += (ihig+1)*ifactor;
            break;
        }
        cout << icount << endl;
    }
}

int main()
{

    return 0;
}
