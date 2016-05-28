#include <iostream>
#include <vector>
using namespace std;

bool verifysquence(vector<int> sequence, int low, int high){
	if(sequence.empty())
		return false;
	if(low >= high)
		return true;
	int root = sequence[high];
	int cur = low;
	while(sequence[cur] < root)
		cur++;
	int mid = cur;
	while(sequence[cur] > root)
		cur++;
	if(cur != high)
		return false;
	bool left = verifysquence(sequence, low, mid-1);
	bool right = verifysquence(sequence, mid, high-1);
	return left&&right;
}

int main(){
	int a[] = {5,7,6,9,10,11,8}, b[] = {7,4,6,5};
	vector<int> vec1(a,a+7), vec2(b,b+4);
	cout << (verifysquence(vec1, 0, vec1.size()-1)? "true":"false") << endl;
	cout << (verifysquence(vec2, 0, vec2.size()-1)? "true":"false") << endl;
}

