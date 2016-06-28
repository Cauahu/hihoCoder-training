#include <iostream>
#include <algorithm>

using namespace std;

int sudu[9][9] = {6,9,0,0,8,0,0,1,2,
		4,0,7,0,1,2,0,3,0,
		0,2,5,0,0,0,8,7,4,
	 	9,0,2,0,5,0,4,8,7,
		0,6,8,0,4,0,3,9,1,
		0,0,1,0,9,0,0,0,0,
		3,0,0,4,0,0,2,0,0,
		0,5,0,1,0,0,0,0,0,
		0,0,0,8,0,6,0,0,0	};

/*
7 2 6 9 0 4 0 5 1
0 8 0 6 0 7 4 3 2
3 4 1 0 8 5 0 0 9
0 5 2 4 6 8 0 0 7
0 3 7 0 0 0 6 8 0
0 9 0 0 0 3 0 1 0
0 0 0 0 0 0 0 0 0
9 0 0 0 2 1 5 0 0
8 0 0 3 0 0 0 0 0

*/
bool check(int num)
{
	int row = num / 9;
	int col = num % 9;
	for(int i=0;i<9;++i)
	{
		if(sudu[row][i] == sudu[row][col] && i != col)
				return false;
	}
	for(int i=0;i<9;++i)
	{
		if(sudu[i][col] == sudu[row][col] && i != row)
				return false;
	}

	int row_x = row / 3 * 3, col_y = col / 3 * 3;
	for(int i=row_x;i<row_x+3;++i)
		for(int j=col_y;j<col_y+3;++j)
			if(sudu[i][j] == sudu[row][col] && i != row && j != col)
				return false;
	return true;
}
bool flag = false;

void backtrace(int count)
{
	if(count == 81){
		for(int i=0;i<9;++i)
		{
			for(int j=0;j<9;++j)
				cout << sudu[i][j];
			cout << endl;
		}
		flag = true;
		return ;
	}
	int row = count / 9, col = count % 9;
	if(sudu[row][col] != 0)
		backtrace(count+1);
	else{
		for(int i=1;i<10;++i)
		{
			sudu[row][col] = i;
			cout << i << endl;
			if(check(count))
				backtrace(count+1);
			if(flag)
				return;
		}
		sudu[row][col]  = 0;
	}
}


int main()
{
	for(int i=0;i<9;++i)
	{
		for(int j=0;j<9;++j)
			cout << sudu[i][j];
		cout << endl;
	}
	
	backtrace(0);
}
