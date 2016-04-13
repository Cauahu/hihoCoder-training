/*
ÌâÄ¿µØÖ·£ºhttp://hihocoder.com/contest/mstest2016april1/problem/1

*/
#include <iostream>

using namespace std;

int main()
{
    int N = 2, P = 10, W = 4, H = 3;
    //int *a = new int[N];
    int a[] = {10,10};
    int font = 1, line = 0, charperline = 0, page = 0;
    while(true)
    {
        charperline = W/font;
        for(int i=0;i<N;i++)
        {
            line += a[i]%charperline==0? a[i]/charperline : a[i]/charperline + 1;
        }
        line *= font;
        page = line%H==0? line/H : line/H + 1;
        cout << "font:" << font << " charperline:" << charperline << " line:" << line << " page:" << page << endl;
        if(page >= P)
            break;
        font++;
        line = 0;
    }

    cout << "font:" << font-1 << endl;

    return 0;
}
