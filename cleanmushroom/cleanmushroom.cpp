#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
	int N, M, K;
	while(cin >> N >> M >> K)
	{
		int mushroom[20][20];
		memset(mushroom, 0, sizeof(mushroom));
		int x, y;
		for(int i=0;i<K;++i)
		{
			cin >> x >> y;
			++mushroom[x-1][y-1];
		}

		if(K <= 2)
		{
			cout << 2 << endl;
			continue;
		}

		int result = 0;
		int step = 0;
		int max_x = 0;
		int max_y = 0;
		int max = 0;
		int boom_num = 0;
		while(step < 2){

			for(int i=0;i<N-2;++i)
			{
				for(int j=0;j<M-2;++j)
				{
					boom_num = 0;
					for(int k=0;k<3;++k)
					{
						for(int h=0;h<3;++h)
						{
							if(mushroom[i+k][j+h] > 0)
								++boom_num;
						}
					}

					if(max < boom_num)
					{
						max = boom_num;
						max_x = i;
						max_y = j;
					}
				}
			}
			result += max;
			for(int i=0;i<3;++i)
			{
				for(int j=0;j<3;++j)
				{
					if(mushroom[max_x+i][max_y+j] > 0)
						--mushroom[max_x+i][max_y+j];
				}
			}

			++step;
			max_x = 0;
			max_y = 0;
			max = 0;
		}

		cout << result << endl;




	}
	return 0;
}
