#include <iostream>

using namespace std;

int sok[100][100]={0};
int pos_per_x,pos_per_y,pos_sok_x,pos_sok_y;//玩家，箱子，目标点的位置
bool movesok(int mx, int my)//以0代表空白格子，以4代表不能通过区域，以1代表玩家，以3代表箱子，以2代表目标点。
{
    if(sok[pos_per_x+mx][pos_per_y+my] == 4)
    {
        return false;
    }
    else if(sok[pos_per_x+mx][pos_per_y+my] == 0)
    {
        sok[pos_per_x][pos_per_y] = 0;
        sok[pos_per_x+mx][pos_per_y+my] = 1;
        pos_per_x += mx;
        pos_per_y += my;
    }
    else
    {
        if(sok[pos_sok_x+mx][pos_sok_y+my] == 4)
            return false;
        else
        {
            //玩家位置变化
            sok[pos_per_x][pos_per_y] = 0;
            sok[pos_per_x+mx][pos_per_y+my] = 1;
            pos_per_x += mx;
            pos_per_y += my;

            //箱子位置变化
            sok[pos_sok_x+mx][pos_sok_y+my] = 3;
            pos_sok_x += mx;
            pos_sok_y += my;
        }
    }
    return true;
}

int main()
{
    int H=4,L=5,n=3;
    //cin >> L >> H >> n;
    /*for(int i=0;i<H;i++)
        for(int j=0;j<L;j++)
        {
            int temp;
            cin >> temp;
            sok[i][j] = temp;
            if(temp == 1)
            {
                pos_per_x = i;
                pos_per_y = j;
            }
            else if(temp == 3)
            {
                pos_sok_x = i;
                pos_sok_y = j;
            }
        }
        5 4 3
00000
13000
00200
00000
4 rurd
6 urdldr
6 rrrurd
        */
        pos_per_x = 1;
        pos_per_y = 0;
        pos_sok_x = 1;
        pos_sok_y = 1;
        sok[1][0] = 1;
        sok[1][1] = 3;
        sok[2][2] = 2;

    //while(n--)
    //{
        int t=4;
        //cin >> t;
        //cout << t << endl;
        char *a = "rurd";
        //for(int i=0;i<t;i++)
         //   cin >> a;
        for(int i=0;i<t;i++)
        {
            switch(a[i])
            {
            case 'u':
                movesok(-1,0);
                break;
            case 'r':
                movesok(0,1);
                break;
            case 'd':
                movesok(1,0);
                break;
            case 'l':
                movesok(0,-1);
                break;
            }

      //  }
    }
    if(sok[pos_sok_x][pos_sok_y] == 2)
        cout << "YES" << endl;
    else
        cout << "NO" <<endl;

    return 0;
}
