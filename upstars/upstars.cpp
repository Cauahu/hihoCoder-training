#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		if(n == 1)
		{
			cout << 0 << endl;
			continue;
		}
		if(n == 2)
		{
			cout << 1 << endl;
			continue;
		}
		if(n == 3)
		{
			cout << 2 << endl;
			continue;
		}
		
		int fib1 = 1, fib2 = 2, fib = 0;
		for(int i=4;i<n;++i)
		{
			fib = fib1 + fib2 ;
			fib1 = fib2;
			fib2 = fib;
			
		}

		cout << fib << endl;
	}
	return 0;
}
