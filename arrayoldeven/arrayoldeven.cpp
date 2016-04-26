#include <iostream>

using namespace std;

void departArray(int *a, int len){
	if(a == NULL || len == 0)
		return;
	int beg = 0, end = len - 1;
	while(beg < end){
		while(beg < end && (a[beg] & 0x1) != 0)
			beg++;
		while(beg < end && (a[end] & 0x1) == 0)
			end--;
		if(beg < end)
			swap(a[beg], a[end]);
	}
}

int main(){
	int a[5] = {1,5,3,4,2};
	for(int i=0;i<5;i++)
		cout << a[i] << " ";
	cout << endl;
	departArray(a, 5);
	for(int i=0;i<5;i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
