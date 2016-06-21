#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getDis(vector<int> A, int n){
	int min = A[0], max = A[0], maxsub = 0;
	for (int i = 1; i < n; ++i)
	{
		if(min > A[i]){
			min = A[i];
			max = A[i];
		}
		if(max < A[i]){
			max = A[i];
			if(maxsub < max - min)
				maxsub = max - min;
		}
	}
	return maxsub;
}

int main(int argc, char const *argv[])
{
	int a[] = {6718,7112,10070,2752,11651,1801,2678,2871,4124,4158,
		7524,9282,9309,1342,4181,8853,12693,4876,11734,2804,
		4561,1850,5538,8539,522,9793,12786,8236,6902,625,
		6768,806,9144,12109,1619,2132,8509,4488,11173,4584,
		6873,7479,12061,4087,9915,2847,6680,844,5533,813,
		2665,12706,5516,8727,9392,310,11276,6989,7638,1817,
		8511,11417,4569,8999,1204,110
	};
	vector<int > A(a, a+66);
	cout << getDis(A, 66) << endl;
	return 0;
}