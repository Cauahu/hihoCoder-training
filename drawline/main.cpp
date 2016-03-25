#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

struct piont
{
    int x_l;
    int x_h;
    int y_l;
    int y_h;
    int ori ;//保存直线的方向
    piont(int a,int b,int c,int d)
    {
        x_l = a;
        x_h = c;
        y_l = b;
        y_h = d;
        if(b == d)
            ori = 1;
        else if(a == c)
            ori = 2;
        else if(d > b)
            ori = 3;
        else
            ori = 4;

    }

};

vector<piont> PNV;

void mergeline(vector<piont>::iterator it,vector<piont>::iterator next)//将两条重叠的线合并
{
    if(it->ori==1)
    {
        it->x_l = (it->x_l<next->x_l)?it->x_l:next->x_l;
        it->x_h = (it->x_h>next->x_h)?it->x_h:next->x_h;
    }
    else if(it->ori==2)
    {
        it->y_l = (it->y_l<next->y_l)?it->y_l:next->y_l;
        it->y_h = (it->y_h>next->y_h)?it->y_h:next->y_h;
    }
    else if(it->ori==3)
    {
        it->x_l = (it->x_l<next->x_l)?it->x_l:next->x_l;
        it->x_h = (it->x_h>next->x_h)?it->x_h:next->x_h;
        it->y_l = (it->y_l<next->y_l)?it->y_l:next->y_l;
        it->y_h = (it->y_h>next->y_h)?it->y_h:next->y_h;
    }
    else
    {
        it->x_l = (it->x_l<next->x_l)?it->x_l:next->x_l;
        it->x_h = (it->x_h>next->x_h)?it->x_h:next->x_h;
        it->y_l = (it->y_l>next->y_l)?it->y_l:next->y_l;
        it->y_h = (it->y_h<next->y_h)?it->y_h:next->y_h;
    }
    PNV.erase(next);


}

void dealline(vector<piont>::iterator it,int x_a,int y_a)//查找相重叠的线
{
    for(auto next=it+1;next!=PNV.end();next++)
    {
        if(it->ori==next->ori)//两条线的方向要一致。
        {
            int temp_x = it->x_l;
            int temp_y = it->y_l;
            while(temp_x!=it->x_h)//第一条线没到头
            {
                if(temp_x==next->x_l||temp_x==next->x_h)//两条线相遇了
                {
                    mergeline(it,next);
                    return;
                }
                temp_x +=x_a;//活动点延斜率方向移动
                temp_y +=y_a;
            }
        }
    }
}

void dealpiont()
{

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&  d);
        piont p(a,b,c,d) ;
        PNV.push_back(p);
    }
    for(auto i=PNV.begin();i!=PNV.end();i++)
    {
        switch(i->ori)//根据斜率决定每次移动的步数
        {
        case 1:
            dealline(i,1,0);
            break;
        case 2:
            dealline(i,0,1);
            break;
        case 3:
            dealline(i,1,1);
            break;
        case 4:
            dealline(i,1,-1);
            break;
        }
    }
    for(auto i=PNV.begin();i!=PNV.end();i++)
    {
        cout << i->x_l << " " << i->y_l << " " << i->x_h << " " << i->y_h << " " << i->ori << endl;
    }
    cout << PNV.size() << endl;

}

int main()
{
    int c;
    cin >> c;
    while(c--)
    {
        dealline();
        PNV.clear();//清空vector
    }


    return 0;
}
