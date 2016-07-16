#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &vec, int first, int last)
{
	int i = first, j = last;
	int key = vec[first];
	while(i < j)
	{
		while(i < j && vec[j] > key)
			--j;
		vec[i++] = vec[j];
		while(i <j && vec[i] < key)
			++i;
		vec[j--] = vec[i];
	}
	vec[i] = key;

	return i;
}


void quik_sort(vector<int> &vec, int first, int last)
{
	if(first < last)
	{
		int mid = partition(vec, first, last);
		quik_sort(vec, first, mid-1);
		quik_sort(vec, mid+1, last);
	}
}

int main()
{
	int a[] = {49, 38, 65, 97, 76, 13, 27};
	vector<int> vec(a,a+7);
	quik_sort(vec, 0, vec.size()-1);

	for(int i=0;i<7;++i)
		cout << vec[i] << endl;
	return 0;
}
