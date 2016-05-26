#include <iostream>

using namespace std;

void HeapAdjust(int heap[], int start, int end){
	for(int i = 2*start+1;i<=end;i=2*i+1){
		if(heap[i] > heap[i-1])
			i--;
		if(heap[i] < heap[i>>1])
			swap(heap[i], heap[i>>1]);
	}
}

void HeapSort(int heap[], int n){
	for(int i=n>>1;i>0;i--)
		HeapAdjust(heap, i ,n);
	for(int i=1;i<=n;i++)
		cout << heap[i] << " ";
	cout << endl;
	for(int i=n;i>1;i--)
	{
		swap(heap[1],heap[i]);
		HeapAdjust(heap, 1, i-1);
	}
	for(int i=1;i<=n;i++)
		cout << heap[i] << " ";
	cout << endl;
}

int main(){
	int heap[] = {0,70,60,12,40,30,8,10};
	HeapSort(heap,7);
	return 0;
}
