#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void merge_dipart(vector<int> &vec, int first, int mid, int last)
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	vector<int> temp ;
	while(i <= m && j <= n)
	{
		if(vec[i] <= vec[j])
			temp.push_back(vec[i++]);
		else
			temp.push_back(vec[j++]);
	}

	while(i <= m)
		temp.push_back(vec[i++]);

	while(j <= n)
		temp.push_back(vec[j++]);

	int len = temp.size();
	for(i = 0;i < len;++i)
		vec[first+i] = temp[i];
}

void merge_sort(vector<int> &vec, int first, int last )
{
	if(first < last)
	{
		int mid = (first + last) / 2;
		merge_sort(vec, first, mid);
		merge_sort(vec, mid+1, last);
		merge_dipart(vec, first, mid, last);
	} 
}


int main()
{
	int a[] = {49, 38, 65, 97, 76, 13, 27};
	vector<int> vec(a, a+7);
	merge_sort(vec, 0, vec.size()-1);
	for(int i=0;i<7;++i)
		cout << vec[i] << endl;

	return 0;
}
