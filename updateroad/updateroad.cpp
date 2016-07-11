#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
	if(a < b)
		swap(a,b);
	int t = a%b;
	while(t)
	{
		a = b;
		b = t;
		t = a%b;
	}
	return b;
}

int main()
{
	int n, a;
	while(cin >> n >> a)
	{
		vector<int> vecb;
		for(int i=0;i<n;++i)
		{
			int num;
			cin >> num;
			cout << num << endl;
			vecb.push_back(num);
		}

		for(int i=0;i<n;++i)
		{
			if(a >= vecb[i]){
				cout << a << " " << vecb[i] << endl;
				a += vecb[i];
			}
			else{
				cout << a << " " << vecb[i] << endl;
				a += gcd(a,vecb[i]);
			}

		}
		cout << a << endl;

	}
}
