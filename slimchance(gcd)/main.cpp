#include <iostream>
#include <cmath>
#include <set>

using namespace std;

/*
gcd算法：辗转相除法，
定理：gcd(a,b)=gcd(b,a mod b)
证明： a可以表示成a = kb+r，则r=a mod b
假设d是a,b的一个公约数，则 d整除a，d整除b，
而r = a - kb，所以d整除r，因此d是b，a mod b的公约数。
*/
int gcd(int a,int b) //求a，b的最大公约数
{
    if(b == 0)
        return a;
    else
        return gcd(b,a%b);
}

set<int> getdivisor(int a)
{
    set<int> s;                         //使用set集合的目的是set的查找非常高效。
    int len = static_cast<int>(sqrt(a*1.0));//提高查找效率
    for(int i=1;i<=len;i++)
    {
        if(a%i==0)
        {
            s.insert(i);
            s.insert(a/i);
        }
    }
    return s;
}

int main()
{
    int a,b;
    cin >> a >> b;
    set<int> s1,s2;
    s1 = getdivisor(a);
    s2 = getdivisor(b);
    int cunt=0;
    for(auto it=s1.begin();it!=s1.end();it++)//统计相同约数。
    {
        if(s2.find(*it)!=s2.end())
            cunt++;
    }
    int len = s1.size()*s2.size();
    int temp = gcd(len,cunt);//处理输出形式，将百分数转化为分数。
    cout << len/temp << " " << cunt/temp << endl;
    return 0;
}
