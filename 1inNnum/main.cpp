/*

���⣺����һ��ʮ���Ƶ�������N��д�´�1��ʼ��N������������Ȼ����һ�����г��ֵ����С�1���ĸ�����
����N=abcde������abcde�ֱ���ʮ������N�ĸ�����λ�ϵ����֡��������Ǽ����λ�ϳ���1�Ĵ������������ܵ��������ص�Ӱ�죺��λ�ϵ����֣�
��λһ�£���λ���ϵ����֡�

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
