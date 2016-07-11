#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		vector<int> vec;
		vector<int> res(n,1);
		for(int i=0;i<n;++i)
		{
			int num;
			cin >> num;
			vec.push_back(num);
		}
		
		for(int i=1;i<n;++i)
		{
			if(vec[i] > vec[i-1])
				res[i] = res[i-1] + 1;
			else if(vec[i] == vec[i-1])
				res[i] = res[i-1];
		}

		for(int i=n-2;i>-1;--i)
		{
			if(vec[i] > vec[i+1])
			{
				int temp = res[i+1] + 1;
				res[i] = res[i] < temp ? temp : res[i];
			}

		}
		int result = 0;
		for(int i=0;i<n;++i)
			result += res[i];

		cout << result << endl;
	}
}
