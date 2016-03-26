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



void add2vec(string s,int level)//将对象放入vector中
{
    const OA temp(s,level);
    auto it=VCWD.begin();
    for(;it!=VCWD.end();it++)//查找vector中是否已经存在实体和层数相同的元素
    {
        if(s == it->name && level == it->level)
            break;
    }
    if(VCWD.empty() || it == VCWD.end())//若不存在则添加
        VCWD.push_back(temp);


}

void dealstringlevel(string &str, string word)
{
    const char * strc = str.c_str();//转化string为const char * 方便处理
    int level=1;
    string s = "";//暂存临时字符串
    for(string::size_type i=0;i<str.length();i++)
    {
        if(strc[i] !='{'&&strc[i] !='}'&&strc[i] !=',')
        {
            s +=strc[i];//统计实体名
        }
        else
        {
            if(s.length())
            {
                add2vec(s,level);
                s = "";
            }
            if(strc[i] =='{')//处理层级
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
