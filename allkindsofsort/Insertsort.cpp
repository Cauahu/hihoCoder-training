#include <iostream>

using namespace std;

void printArray(int a[], int n){
	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	cout <<  endl;
}
void InsertSort(int a[], int n){
	for(int i=1;i<n;i++){
		for(int j=i;j>0&&a[j]>a[j-1];j--){
			int temp = a[j];
			a[j] = a[j-1];
			a[j-1] = temp;
		}
		printArray(a, n);
	}
}


int main(){
	int a[] = {4,1,3,2,5};
	InsertSort(a, 5);
}
