/*
http://www.nowcoder.com/practice/72a99e28381a407991f2c96d8cb238ab?tpId=49&tqId=29305&rp=2&ru=%2Fta%2F2016test&qru=%2Fta%2F2016test%2Fquestion-ranking

小东所在公司要发年终奖，而小东恰好获得了最高福利，他要在公司年会上参与一个抽奖游戏，游戏在一个6*6的棋盘上进行，上面放着36个价值不等的礼物，每个小的棋盘上面放置着一个礼物，他需要从左上角开始游戏，每次只能向下或者向右移动一步，到达右下角停止，一路上的格子里的礼物小东都能拿到，请设计一个算法使小东拿到价值最高的礼物。
给定一个6*6的矩阵board，其中每个元素为对应格子的礼物价值,左上角为[0,0],请返回能获得的最大价值，保证每个礼物价值大于100小于1000。


*/

#include <iostream>
#include <vector>

using namespace std;

int main(
{
	int a[][6] = {
		1,0,0,0,0,0,
		0,1,0,0,0,0,
		0,0,1,0,0,0,
		0,0,0,1,0,0,
		0,0,0,0,1,0,
		0,0,0,0,0,1
	};
	vector<vector<int> > vec;
	vec.push_back(vector<int>(a[0],a[0]+6));
	vec.push_back(vector<int>(a[1],a[1]+6));
	vec.push_back(vector<int>(a[2],a[2]+6));
	vec.push_back(vector<int>(a[3],a[3]+6));
	vec.push_back(vector<int>(a[4],a[4]+6));
	vec.push_back(vector<int>(a[5],a[5]+6));
	
	vector<vector<int> > result;
	int a1[6] = {0};
	result.push_back(vector<int>(a1,a1+6));
	result.push_back(vector<int>(a1,a1+6));
	result.push_back(vector<int>(a1,a1+6));
	result.push_back(vector<int>(a1,a1+6));
	result.push_back(vector<int>(a1,a1+6));
	result.push_back(vector<int>(a1,a1+6));
	
	for(int i=0;i<6;++i)
	{
		for(int j=0;j<6;++j)
			cout << result[i][j] << " ";
		cout << endl;
	}
	result[0][0] = vec[0][0];
	for(int i=1;i<6;++i)
		result[0][i] = result[0][i-1] + vec[0][i];
	
	for(int i=1;i<6;++i)
		result[i][0] = result[i-1][0] + vec[i][0];

	for(int i=1;i<6;++i)
	{
		for(int j=1;j<6;++j)
		{
			if(result[i-1][j] > result[i][j-1])
				result[i][j] = result[i-1][j] + vec[i][j];
			else
				result[i][j] = result[i][j-1] + vec[i][j];
		}
	}

	cout << "after:\n" ;
	for(int i=0;i<6;++i)
	{
		for(int j=0;j<6;++j)
			cout << result[i][j] << " ";
		cout << endl;
	}
	cout << result[5][5] << endl;
	
	/*
	for(int i=0;i<6;++i)
	{
		for(int j=0;j<6;++j)
			cout << vec[i][j] << " ";
		cout << endl;
	}
	*/

	return 0;
}
