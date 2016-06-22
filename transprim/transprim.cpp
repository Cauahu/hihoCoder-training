#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n = 0, c = 0;
	long long int t, value, a[200002] ;
	while(scanf("%d %lld %d", &n, &t, &c) != EOF){
		int sum = 0;
		value = 0;
		for(int i=0;i<n;++i)
			scanf("%lld", &a[i]);
		for(int i=0;i<c;++i)
			value += a[i];
		for(int i=0;i <= n-c;++i){
			if(value <= t)
				++sum;
			value -= a[i];
			value += a[i+c];
		}

		printf("%d\n", sum );


	}
	return 0;
}