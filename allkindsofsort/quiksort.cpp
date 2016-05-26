#include <iostream>
#include <vector>

using namespace std;

void qsort(vector<int> &vec, int l, int h){
	if(l < h){
		int key = vec[l];
		int left = l, right = h;
		while(left < right){
			while(left < right && vec[right] > key)
				right--;
			vec[left] = vec[right];
			while(left < right && vec[left] < key)
				left++;
			vec[right] = vec[left];
		}
		vec[left] = key;
		for(vector<int>::iterator it = vec.begin();it!=vec.end();it++)
			cout << *it << " ";
		cout << endl;
		qsort(vec, l, left-1);
		qsort(vec, left+1, h);
	}
}

void qsort1(vector<int> &vec, int l, int h){
	if(l < h){
		int m =l, key = vec[l];
		for(int i=l+1;i < h;i++)
		{
			if(vec[i] < key )
				swap(vec[m++], vec[i]);
		}
		vec[m] = key;
		for(vector<int>::iterator it = vec.begin();it!=vec.end();it++)
			cout << *it << " ";
		cout << endl;
		qsort1(vec, l, m-1);
		qsort1(vec, m+1, h);
	}
}
int main(){
	int a[] = {55,41,59,26,53,58,97,93};
	vector<int> vec(a, a+8);
	qsort1(vec, 0, vec.size()-1);
	for(vector<int>::iterator it = vec.begin();it!=vec.end();it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}
