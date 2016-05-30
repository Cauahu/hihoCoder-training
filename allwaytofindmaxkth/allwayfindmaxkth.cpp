#include <iostream>
#include <vector>
#include <set>
using namespace std;

int slution_divide(vector<int> &vec, int l, int h, int k){			//分治法
	if(l < h){
		int left = l, right = h, key = vec[l];
		while(left < right){
			while(left < right && vec[right] > key)
				right--;
			swap(vec[left], vec[right]);
			while(left < right && vec[left] < key)
				left++;
			swap(vec[left], vec[right]);
		}
		swap(vec[left], key);
		if(left-l < k-1)
			return slution_divide(vec, left+1, h, k-left+l-1);
		else if(left-l > k-1)
			return slution_divide(vec, l, left-1, k );
		return vec[left];
	}
}

int solution_heapbyset(vector<int> vec, int k){
	set<int> se(vec.begin(), vec.end());
	set<int>::iterator it = se.begin();
	while(it != se.end())
		cout << *it++ << " ";
	cout << endl;
	it = se.begin();
	while(k-- && it != se.end())
		it++;
	
}

int main(){
	int a[] = {55,41,59,26,53,58,97,93};
	vector<int> vec(a,a+8);
//	cout << slution_divide(vec,0,vec.size()-1, 4) << endl;
//	cout << slution_divide(vec,0,vec.size()-1, 2) << endl;
//	cout << slution_divide(vec,0,vec.size()-1, 6) << endl;
	solution_heapbyset(vec, 4);
	return 0;
}
