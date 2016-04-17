#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

typedef struct IPadress
{
    int ad[4];
    int mask;
}IPAD;


bool compIP(IPAD IP, IPAD IPtest)//判断IP地址是否合法
{
    int shift_non = IP.mask/8, shift_fin = IP.mask%8, i;//shift_non 无需移位，shitf_fin需要移位
    bool is_matched = true;
    for(i=0;i<shift_non;i++)
    {
        if(IP.ad[i] != IPtest.ad[i])
        {
            is_matched = false;
            return is_matched;
        }
    }
    if(shift_fin != 0)//比较子网掩码最后几位
    {
        int a = IP.ad[i] >> (8-shift_fin);
        int b = IPtest.ad[i] >> (8-shift_fin);
        is_matched = a&b? true:false;
    }
    return is_matched;
}


int main()
{
    /*
    allow 1.2.3.4/30
    deny 1.1.1.1
    allow 127.0.0.1
    allow 123.234.12.23/3
    deny 0.0.0.0/0
    1.2.3.4
    1.2.3.5
    1.1.1.1
    100.100.100.100
    219.142.53.100
    */

    int N , M;
    cin >> N >> M;
    vector<IPAD> IP;
    vector <IPAD> IPtest;
    for(int i=0;i<N;i++)
    {
        char pass[10],mask_flag;
        int ip_1, ip_2, ip_3, ip_4, mask = 32;
        scanf("%s",pass);
        scanf("%d.%d.%d.%d",&ip_1,&ip_2,&ip_3,&ip_4);
        mask_flag = getchar();
        if(mask_flag == '/')
            scanf("%d",&mask);
        if(pass[0] == 'a')
        {
            IPAD ip;
            ip.ad[0] = ip_1;
            ip.ad[1] = ip_2;
            ip.ad[2] = ip_3;
            ip.ad[3] = ip_4;
            ip.mask = mask;
            IP.push_back(ip);
        }
    }
    for(auto i=IP.begin();i!=IP.end();i++)
    {
        cout << (*i).ad[0] << "." << (*i).ad[1] << "." << (*i).ad[2] << "." << (*i).ad[3] << "/" << (*i).mask << endl;
    }
    for(int i=0;i<M;i++)
    {
        int ip_1, ip_2, ip_3, ip_4;
        scanf("%d.%d.%d.%d",&ip_1,&ip_2,&ip_3,&ip_4);
            IPAD ip;
            ip.ad[0] = ip_1;
            ip.ad[1] = ip_2;
            ip.ad[2] = ip_3;
            ip.ad[3] = ip_4;
            IPtest.push_back(ip);
    }
    for(auto i=IPtest.begin();i!=IPtest.end();i++)
    {
        cout << (*i).ad[0] << "." << (*i).ad[1] << "." << (*i).ad[2] << "." << (*i).ad[3] << endl;
    }

    for(auto i=IPtest.begin();i!=IPtest.end();i++)
    {
        bool flag = false;
        for(auto j=IP.begin();j!=IP.end();j++)
            flag = compIP(*j, *i);
        cout << (flag?"YES":"NO") << endl;
    }
    return 0;
}
