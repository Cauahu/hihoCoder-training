#include <iostream>
#include <vector>
using namespace std;

int main(){
	int a[] = {1,2,4,7,11,15};
	vector<int> array(a, a+6);
	vector<int>::iterator itb = array.begin(), ite = array.end()-1;
	int multip = 999999, temp = 0, sum = 15;
	while(*itb < *ite){
		temp = *itb + *ite;
		if(temp > sum)
			--ite;
		else if(temp < sum)
			++itb;
		else{
			if(*itb* *ite < multip){
				multip = *itb * *ite;
				cout << *itb << " " << *ite << endl;
			}
			++itb;
			--ite;
		}

	}
	return 0;
}
