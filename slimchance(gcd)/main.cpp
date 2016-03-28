#include <iostream>
#include <cmath>
#include <set>

using namespace std;

/*
gcd�㷨��շת�������
����gcd(a,b)=gcd(b,a mod b)
֤���� a���Ա�ʾ��a = kb+r����r=a mod b
����d��a,b��һ����Լ������ d����a��d����b��
��r = a - kb������d����r�����d��b��a mod b�Ĺ�Լ����
*/
int gcd(int a,int b) //��a��b�����Լ��
{
    if(b == 0)
        return a;
    else
        return gcd(b,a%b);
}

set<int> getdivisor(int a)
{
    set<int> s;                         //ʹ��set���ϵ�Ŀ����set�Ĳ��ҷǳ���Ч��
    int len = static_cast<int>(sqrt(a*1.0));//��߲���Ч��
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
    for(auto it=s1.begin();it!=s1.end();it++)//ͳ����ͬԼ����
    {
        if(s2.find(*it)!=s2.end())
            cunt++;
    }
    int len = s1.size()*s2.size();
    int temp = gcd(len,cunt);//���������ʽ�����ٷ���ת��Ϊ������
    cout << len/temp << " " << cunt/temp << endl;
    return 0;
}
