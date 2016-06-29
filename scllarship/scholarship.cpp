#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n, r, avg ;
	while(cin >> n >> r >> avg)
	{
		multimap<int, int> mp;
		int a, b, sum = n*avg;
		for(int i=0;i<n;++i)
		{
			cin >> a >> b;
			mp.insert(make_pair(b,a));
			sum -= a;
		}

/*
		mp.insert(make_pair(5,0));
		mp.insert(make_pair(1,9));
		mp.insert(make_pair(1,8));
		mp.insert(make_pair(1,0));
		mp.insert(make_pair(100,9));
		sum -= 26;*/


/*		multimap<int, int>::iterator it1 = mp.begin();
		while(it1 != mp.end())
		{
			cout << it1->first << " " << it1->second << endl;
			++it1;
		}
		cout << endl;
*/
		if(sum <= 0)
			cout << 0 << endl;
		else{
			int time = 0;
			multimap<int, int>::iterator it = mp.begin();
			//cout << "before while sum = " << sum << endl;
			while(it != mp.end())
			{
				sum -= (r - it->second);
				//cout << sum << endl;
				if(sum <= 0)
				{
					time += (sum+r-it->second)*it->first;
					cout << time << endl;
					break;
				}
				else
					time += (r - it->second)*it->first;
				++it;
			}
		}

	}
	return 0;

}
