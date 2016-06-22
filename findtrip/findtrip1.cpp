#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int N = 0, M = 0;
int mush[20][20] = {0};
void countpath(int x, int y, double &sum){
	if(x > N || y > M || mush[x][y] == 1)
		return ;
	if(x == N && y == M){
		++sum;
		return ;
	}
	countpath(x+1, y, sum) ;
	countpath(x, y+1, sum) ;
}

void countpathsum(int x, int y, double &sum){
	if(x > N || y > M )
		return ;
	if(x == N && y == M){
		++sum;
		return ;	
	}
	countpathsum(x+1, y, sum) ;
	countpathsum(x, y+1, sum) ;
}


int main(int argc, char const *argv[])
{
	int num = 0;
	while(cin >> N >> M >> num){
		for (int i = 0; i < num; ++i)
		{
			int x, y;
			cin >> x >> y;
			mush[x][y] = 1;
		}
		double pathtatol = 0, pathsuccess = 0;
		countpath(1, 1, pathsuccess);
		countpathsum(1, 1, pathtatol);
		printf("%.2f\n",  (pathtatol ?  pathsuccess/pathtatol : pathtatol ) );
		//cout << (pathtatol ?  pathsuccess/pathtatol : pathtatol )<< endl;
	}
	return 0;
}