/*/http://www.nowcoder.com/practice/c61211485dbf495d8d98e91b6e250422?tpId=49&tqId=29304&rp=2&ru=%2Fta%2F2016test&qru=%2Fta%2F2016test%2Fquestion-ranking

  一只兔子藏身于20个圆形排列的洞中（洞从1开始编号），一只狼从x号洞开始找,下次隔一个洞找(及在x＋2号洞找)，在下次个两个洞找(及在x＋5号洞找)，它找了n次仍然没有找到。问兔子可能在那些洞中

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int x, n;
	while(cin >> x >> n)
	{
		vector<int> vec(20,0);
		int time = 2;
		//for(int i=0;i<20;++i)
		//	cout << vec[i] << " ";
		x--;
		while(n--){
			vec[x] = 1;
			x += time++;
			x = x % 20;
		}
		//for(int i=0;i<20;++i)
		//	cout << vec[i] << " ";
		if(find(vec.begin(),vec.end(),0) == vec.end())
			cout << -1;
		else{
			int num = count(vec.begin(), vec.end(), 0);
			for(int i=0;i<20;++i)
			{
				if(vec[i] == 0 && num--)
					cout << i + 1<< " ";
				else if(vec[i] == 0)
					cout << i;
			}
		}
	}
	return 0;
}
