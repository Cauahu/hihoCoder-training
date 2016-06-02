#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
	int a[] = {2,4,3,6,3,2,5,5};
	vector<int> data(a,a+8);
	map<int,int> searchmap;
	vector<int>::iterator it = data.begin();
	while(it != data.end()){
	map<int, int>::iterator itm = searchmap.find(*it);
	if(itm == searchmap.end())
 		searchmap[*it] = 1;
        else
		itm->second++;
	++it;
    	}
	while(itm != searchmap.end() && itm->second != 1)
	itm++;
	int num1 = itm->first;
	itm++;
	while(itm != searchmap.end() && itm->second != 1)
        itm++;
	int num2 = itm->first;   
	cout << "num1:" << num1 << " num2:" << num2 << endl;
	return 0;
}
