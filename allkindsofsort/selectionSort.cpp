#include <iostream>

using namespace std;

void selectionsort(int a[], int n){
	for(int i=0;i<n-1;i++){
		int smallest = i;
		for(int j=i+1;j<n;j++){
			if(a[smallest]>a[j])
				smallest = j;
		}
		int temp = a[smallest];
		a[smallest] = a[i];
		a[i] = temp;
	}
}

int main(){

	return 0;
}
