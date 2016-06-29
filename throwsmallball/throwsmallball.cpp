#include <iostream>

using namespace std;

int main()
{
//	int A = 100, B = 90, C = 80, D = 70;
	int a[] = {100, 90, 80, 70};
	int sum = 0;
	for(int i=0;i<4;++i)
	{
		sum += a[i];
		a[i] = a[i] >> 1;
		while(a[i]){
//			cout << a[i] << endl;
			sum += 2*a[i];
			a[i] = a[i] >> 1;
		}
	}
/*	int n = 340;
	sum = 0;
	while(n){
			cout << n << endl;
			sum += n;
			n = n >> 1;
		}
*/
	cout << sum << endl;

	return 0;
}
