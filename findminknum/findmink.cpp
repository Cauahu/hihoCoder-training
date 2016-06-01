#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &vec,int beg, int end){
	if(beg < end){
		int key = vec[beg];
		int low = beg, high = end;
		while(low < high){
			while(low < high && key < vec[high])
				--high;
			vec[low] = vec[high];
			while(low < high && key > vec[low])
				++low;
			vec[high] = vec[low];
		}
		vec[low] = key;
		return low;
	}
	return -1;
}

void findmink(vector<int> &vec, int k){
	int beg = 0, end = vec.size()-1, position = partition(vec, beg, end);
	while(position != k-1){
		if(position > k-1){
			end = position - 1;
			position = partition(vec,beg, end);
		}else{
			beg = position+1;
			position = partition(vec, beg, end);
		}
	}
	for(int i=0;i<=position;++i)
		cout << vec[i] << " ";
	cout << endl;
}

int main(){
	int a[] = {4,5,1,6,2,7,3,8};
	vector<int> vec(a,a+8);
	findmink(vec, 4);
	return 0;
}
