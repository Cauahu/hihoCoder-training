#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

struct OA
{
    string name;
    int level;
    OA(string s,int l)
    {
        name = s;
        level = l;
    }
};

vector<OA> VCWD;



void add2vec(string s,int level)//���������vector��
{
    const OA temp(s,level);
    auto it=VCWD.begin();
    for(;it!=VCWD.end();it++)//����vector���Ƿ��Ѿ�����ʵ��Ͳ�����ͬ��Ԫ��
    {
        if(s == it->name && level == it->level)
            break;
    }
    if(VCWD.empty() || it == VCWD.end())//�������������
        VCWD.push_back(temp);


}

void dealstringlevel(string &str, string word)
{
    const char * strc = str.c_str();//ת��stringΪconst char * ���㴦��
    int level=1;
    string s = "";//�ݴ���ʱ�ַ���
    for(string::size_type i=0;i<str.length();i++)
    {
        if(strc[i] !='{'&&strc[i] !='}'&&strc[i] !=',')
        {
            s +=strc[i];//ͳ��ʵ����
        }
        else
        {
            if(s.length())
            {
                add2vec(s,level);
                s = "";
            }
            if(strc[i] =='{')//����㼶
                level++;
            else if(strc[i] =='}')
                level--;

        }
    }
    for(auto it = VCWD.end()-1;it!=VCWD.begin()-1;it--)
    {
        if(it->name == word)
            cout << it->level<< " ";
    }
    cout << endl;
}

int main()
{
    string one = "Fruit{apple{shape,color},orange{taste,price}}";
    string two = "Fruit{apple{shape,color},orange{taste,price}}";
    string three = "Fruit{apple{shape,color},orange{color,price},color}";
    string word1 = "Fruit";
    string word2 = "orange";
    string word3 = "color";
    dealstringlevel(one,word1);
    dealstringlevel(two,word2);
    dealstringlevel(three,word3);
    return 0;
}
