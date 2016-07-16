#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void selection_sort(vector<int> &vec)
{
	int len = vec.size();
	for(int i=0;i<len;++i)
	{
		int min = i;
		for(int j=i+1;j<len;++j)
			if(vec[j] < vec[min])
				min = j;
		swap(vec[i], vec[min]);
	}
}

int main()
{
	int a[] = {49, 38, 65, 97, 76, 13,27};
	vector<int> vec(a, a+7);
	selection_sort(vec);
	for(int i=0;i<7;++i)
		cout << vec[i] << endl;
}
