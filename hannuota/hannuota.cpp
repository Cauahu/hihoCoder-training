#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> first, pair<int, int> second)
{
	return first.first > second.first;
}

int main()
{
	int n;
	while(cin >> n)
	{
		vector<pair<int,int> > recoder;
		int num, hight, weight;
		/*
		for(int i=0;i<n;++i)
		{
			cin >> num >> hight >> weight;
			recoder.insert(hight, weight);
		}
		*/

		recoder.push_back(pair<int,int>(65, 100));
		recoder.push_back(pair<int,int>(75, 80));
		recoder.push_back(pair<int,int>(80, 100));
		recoder.push_back(pair<int,int>(60, 95));
		recoder.push_back(pair<int,int>(82, 101));
		recoder.push_back(pair<int,int>(81, 70));

		sort(recoder.begin(), recoder.end(),cmp);

		int len = recoder.size();
		vector<int > hannuo(len,1);
		vector<pair<int, int> >::iterator iti = recoder.begin() +1,itend = recoder.end();
		int veci = 1;
		while(iti<itend)
		{
			int tempi = 0; 
			vector<pair<int, int> >::iterator itj = recoder.begin() ;
			while(itj<iti)
			{
				if(iti->second <= itj->second )
					hannuo[veci] = max(hannuo[veci],hannuo[tempi]+1 );
				++tempi;
				++itj;
			}
			++veci;
			++iti;
		}
		cout << *max_element(hannuo.begin(), hannuo.end());
	}

	return 0;
}
