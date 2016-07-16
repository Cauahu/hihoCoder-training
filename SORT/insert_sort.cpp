#include <iostream>
#include <vector>

using namespace std;

void insert_sort(vector<int> &vec)
{
	int len = vec.size();
	for(int i=1;i<len;++i)
	{
		int j = i-1;
		int key = vec[i];
		while(j >= 0 && vec[j] > key)
		{
			vec[j+1] = vec[j];
			--j;
		}
		vec[j+1] = key;
	}
}

 int main()
{
	int a[ ] = {49, 38, 65, 97, 76, 13, 27};
	vector<int> vec(a, a+7);
	insert_sort(vec);
	for(int i = 0;i < 7;++i)
		cout << vec[i] << endl;
	return 0;
}