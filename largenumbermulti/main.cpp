/*#include <iostream>

#include <string>
#include <algorithm>
#include <string.h>


using namespace std;


void bignummulti(string num1, string num2) //处理大数乘法
{
    const char * num1_c = num1.c_str();//将string转化为char *类型，方便操作。
    const char * num2_c = num2.c_str();
    cout << "num1:" << num1_c << "  num2:" << num2_c << endl;
    int * res = new int(num1.length()+num2.length());//分配存放结果的数组。
    memset(res,0,(num1.length()+num2.length())*sizeof(int));
    unsigned int resflag = 0,i,j ;//resflag用于标记每个位乘后的偏移。
    for(i=0;i<num1.length();i++)
    {
        int carrym = 0,carrya = 0;//乘法进位和加法进位。
        for(j=0;j<num2.length();j++)
        {
            int sum = (num1_c[i]-'0')*(num2_c[j]-'0')+carrym;//乘法结果
            carrym = sum/10;//乘法进位
            res[resflag+j] = sum%10+res[resflag+j]+carrya;//加法结果。
            sum = res[resflag+j]%10;//保存加法结果个位
            carrya = res[resflag+j]/10;//加法进位
            res[resflag+j] = sum;//存储加法结果个位
        }
        res[resflag+j] = (carrym + carrya)%10;//处理最后进位
        carrya = (carrym + carrya)/10;
        res[resflag+j+1] += carrya;
        resflag++;//偏移一位。
    }
    resflag += j;
    while(resflag--)//输出
        cout << res[resflag] ;
}


int main()
{
    string num1 = "987";
    string num2 = "654";
    //645498
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    bignummulti(num1, num2);

    return 0;
}*/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void normal(vector<int>& num)
{
    //处理可能的进位
    num.push_back(0);
    for(int i = 0;i<num.size();i++)
    {
        num[i+1] += num[i]/10;
        num[i] %= 10;
    }
    while(num.size()>1 && num.back()==0)
        num.pop_back();
}

vector<int> multiply(vector<int>& a,vector<int>& b)
{
    vector<int> c(a.size()+b.size()+1,0);
    for(int i = 0;i<a.size();i++)
    {
        for(int j = 0;j<b.size();j++)
            c[i+j] += a[i]*b[j];
    }
    normal(c);
    return c;
}


int main()
{
    return 0;
}


