#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Bubble_sort(vector<int> &vec)
{
	int len = vec.size();
	for(int i=len-1;i>0;--i)
	{
		for(int j=1;j<=i;++j)
		{
			if(vec[j-1] > vec[j])
				swap(vec[j-1], vec[j]);
		}
	}
}


int main()
{
	int a[] = {49, 38, 65, 97, 76, 13, 27};
	vector<int> vec(a, a+7);
	Bubble_sort(vec);
	for(int i=0;i<7;++i)
		cout << vec[i] << endl;


}
