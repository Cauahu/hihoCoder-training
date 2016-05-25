#include <iostream>
#include <vector>

using namespace std;

void adjuge(vector<int> &vec){
	vector<int>::iterator beg = vec.begin(), en = vec.end()-1;
	while(beg < en){
		while((*beg&1) == 1)
			beg++;
		while((*en&1) == 0)
			en--;
		swap(*beg, *en);
		beg++;
		en--;
	}
}

int main(){
	int a[] = {1,2,3,4,5,6,7,8};
	vector<int> vec(a, a+8);
	adjuge(vec);
}
