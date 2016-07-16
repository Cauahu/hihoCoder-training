#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heap_adjust(vector<int> &vec, int i, int n)
{
	int j = 2*i;
	while(j < n)
	{
		if(j+1 < n && vec[j+1] > vec[j])
			++j;
		if(vec[j] > vec[i])
			swap(vec[j], vec[i]);
		++i;
		j = 2*i;
	}
}

void heap_create(vector<int> &vec )
{
	int len = vec.size();
	for(int i=len/2;i>0;--i)
		heap_adjust(vec, i, len);
}

void heap_sort(vector<int> &vec)
{
	heap_create(vec);

	int n = vec.size();
	while(n > 1)
	{
		swap(vec[1], vec[--n]);
		heap_adjust(vec, 1, n);
	}

}

int main()
{
	int a[] = {0, 49, 38, 65, 97, 76, 13, 27};
	vector<int> vec(a, a+8);
	heap_sort(vec);

	for(int i=0;i<8;++i)
		cout << vec[i] << endl;

	return 0;
}
