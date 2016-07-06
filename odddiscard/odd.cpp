#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	while(cin >> n){
		if(n == 0)
		{
			cout << 0 << endl;
			continue;
		}
		if(n == 1)
		{
			cout << 1 << endl;
			continue;
		}

		int i=1;
		while(i <= n){
			cout << i << " ";
			i = (i<<1) + 1;
		}
		cout << "\n" << (i>>1) << endl;
	}
	return 0;
}
