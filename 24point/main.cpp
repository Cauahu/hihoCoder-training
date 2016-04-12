#include <iostream>
#include <string>
#include <math.h>

using namespace std;

const double Thershold = 1E-6;
const int NUM = 4;
const int ResultValue = 24;
double number[] = {1,2,7,7};
string result[] = {"1","2","7","7"};


bool PointGame(int n)
{
    if(n == 1)
    {
        if(fabs(number[0]-ResultValue) < Thershold)
        {
            cout << result[0] << endl;
            cout << number[0] << endl;
            return true;
        }
        else
        {
            return false;
        }
    }
    for(int i=0;i<NUM;i++)
    {
        for(int j=i+1;j<NUM;j++)
        {
            double a,b;
            string expa,expb;

            a = number[i];
            b = number[j];
            number[j] = number[n-1];//将最后一个数前移。

            expa = result[i];
            expb = result[j];
            result[j] = result[n-1];//将最后一个表达式前移

            //分别计算不同情况的组合，组合情况有a+b，a-b，b-a，a*b，a/b，b/a，然后进行递归

            result[i] = "(" + expa + "+" + expb + ")";
            number[i] = a+b;
            if(PointGame(n-1))
                return true;

            result[i] = "(" + expa + "-" + expb + ")";
            number[i] = a-b;
            if(PointGame(n-1))
                return true;

            result[i] = "(" + expb + "-" + expa + ")";
            number[i] = b-a;
            if(PointGame(n-1))
                return true;

            result[i] = "(" + expa + "*" + expb + ")";
            number[i] = a*b;
            if(PointGame(n-1))
                return true;

            if(b != 0)
            {
                result[i] = "(" + expa + "/" + expb + ")";
                number[i] = a/b;
                if(PointGame(n-1))
                    return true;
            }
            if(a != 0)
            {
                result[i] = "(" + expb + "/" + expa + ")";
                number[i] = b/a;
                if(PointGame(n-1))
                    return true;
            }
            number[i] = a;
            number[j] = b;
            result[i] = expa;
            result[j] = expb;
        }
    }
    return false;

}
int main()
{

    PointGame(NUM);
    return 0;
}
