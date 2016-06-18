#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, k;
	while(scanf("%d%d",&n, &k) != EOF){
		int prefer[n][k+1];
		int val;
		for(int i=0;i<n;++i)
			for(int j=0;j<k+1;++j){
				scanf("%d", &val);
				prefer[i][val] = j;
			}
		int place = 0;
		for(int j=k;j>=1;--j){
			int n_choose = 0;
			for(int i=0;i<n;++i){
				if(prefer[i][j] < prefer[i][place])
					++n_choose;
			}
			if(n_choose > n>>1)
				place = j;
		}
		if(place == 0)
			printf("otaku\n");
		else
			printf("%d\n", place );
	}
	return 0;
}