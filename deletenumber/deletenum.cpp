#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	while(cin >> n)
	{
		vector<int> vec(n);
		for(int i=0;i<n;++i)
			vec[i] = i;
		int cur = 0, t = 0;
		while(vec.size() != 1)
		{
			if(t == 2)
			{
				if(cur >= vec.size())
					cur = cur % vec.size();
				vector<int>::iterator it = vec.begin() + cur;
				vec.erase(it);
				t = 0;
				--cur;
			}
			else
				++t;
			++cur;			
		}
		cout << vec[0] << endl;
	}

	return 0;
}
