#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>


using namespace std;


void bignummulti(string num1, string num2) //��������˷�
{
    const char * num1_c = num1.c_str();//��stringת��Ϊchar *���ͣ����������
    const char * num2_c = num2.c_str();
    cout << "num1:" << num1_c << "  num2:" << num2_c << endl;
    int * res = new int(num1.length()+num2.length());//�����Ž�������顣
    memset(res,0,(num1.length()+num2.length())*sizeof(int));
    unsigned int resflag = 0,i,j ;//resflag���ڱ��ÿ��λ�˺��ƫ�ơ�
    for(i=0;i<num1.length();i++)
    {
        int carrym = 0,carrya = 0;//�˷���λ�ͼӷ���λ��
        for(j=0;j<num2.length();j++)
        {
            int sum = (num1_c[i]-'0')*(num2_c[j]-'0')+carrym;//�˷����
            carrym = sum/10;//�˷���λ
            res[resflag+j] = sum%10+res[resflag+j]+carrya;//�ӷ������
            sum = res[resflag+j]%10;//����ӷ������λ
            carrya = res[resflag+j]/10;//�ӷ���λ
            res[resflag+j] = sum;//�洢�ӷ������λ
        }
        res[resflag+j] = (carrym + carrya)%10;//��������λ
        carrya = (carrym + carrya)/10;
        res[resflag+j+1] += carrya;
        resflag++;//ƫ��һλ��
    }
    resflag += j;
    while(resflag--)//���
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
}
