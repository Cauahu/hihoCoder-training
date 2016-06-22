#include <iostream>
#include <string.h>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int N = 0, M = 0, K = 0;	
	while(cin >> N >> M >> K){
		int mushroom[21][21] ;
		double prob[21][21] ;
		memset(mushroom,0 , sizeof(mushroom));
		memset(prob,0 , sizeof(prob));
		/*for (int i = 0; i < 21; ++i)
		{
			for (int j = 0; j < 21; ++j)
			{
				cout << prob[i][j] << " " ;
			}
			cout << endl;
		}
*/
		for (int i = 0; i < K; ++i)
		{
			int x, y;
			cin >> x >> y;
			mushroom[x][y] = 1;
		}

		prob[1][1] = 1;

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				if(i == 1&& j == 1) 
					continue;
				if(mushroom[i][j] )
					prob[i][j] = 0;
				else{
					if(j == M)
						prob[i][j] += prob[i-1][j] * 0.5;
					if(i == N)
						prob[i][j] += prob[i][j-1] * 0.5;
					prob[i][j] += prob[i-1][j] * 0.5 + prob[i][j-1] * 0.5;
				}
			}
		}
		printf("%.2f\n", prob[N][M] );
		//cout << prob[N][M] << endl;
	}
	return 0;
}