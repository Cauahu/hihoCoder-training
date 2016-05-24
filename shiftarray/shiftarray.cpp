#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int > vec){
	for(vector<int>::iterator it=vec.begin();it!=vec.end();it++){
		cout << *it << " ";
	}
	cout << endl;
}

void shiftarray(vector<int> a, int rotdist){
	int len = a.size();
	for(int i=0;i<rotdist;i++){
		int temp = a[i];
		int j = i, k = j + rotdist;
		while(k < len){
			a[j] = a[k];
			j = k;
			k = j + rotdist;
		}
		a[j] = temp;	
		printArray(a);
	}
}

int main(){
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> vec(a, a+10);
	
	shiftarray(vec, 3);
	return 0;
}

