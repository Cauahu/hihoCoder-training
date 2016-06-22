#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coutArea(vector<int> A, int n){
	int max = 0;
	int temparea = 0;
	for(int i=0;i<n;++i){
		int col = 1;
		for(int j=i+1;j<n;++j){
			if(A[j] < A[i])
				break;
			++col;
		}
		for(int j=i-1;j>=0;--j){
			if(A[j] < A[i])
				break;
			++col;
		}
		temparea = A[i] * col;
		if(temparea > max)
			max = temparea;
	}
	return max;
}

int main(int argc, char const *argv[])
{
	int a[] = {2,7,9,4,1};
	vector<int > A(a, a+5);
	cout << coutArea(A, A.size()) << endl; 
	return 0;
}