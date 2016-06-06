#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


multiset<int> ms;

void Insert(int num)
{
        ms.insert(num);
}

double GetMedian()
{ 
	multiset<int>::iterator it = ms.begin();
	/*for(;it != ms.end();++it)
		cout << *it << " ";
	cout << endl;
	*/
   	int v = ms.size(), loop = v/2;
   	double result = 0.0;
   	//cout << "v: " << v << "loop: " << loop << endl;
   	it = ms.begin();
    	while(loop > 0){
        		++it;
        		--loop;
	}
	result = *it--;
    	if(v % 2 == 0){
	    	result = (result + *it) / 2;
}
	   	
    return result;
}
    
int main() {

	//[5,2,3,4,1,6,7,0,8]
	Insert(5);
	cout << GetMedian() << endl << endl;
	Insert(2);
	cout << GetMedian() << endl << endl;
	Insert(3);
	cout << GetMedian() << endl << endl;
	Insert(4);
	cout << GetMedian() << endl << endl;
	Insert(1);
	cout << GetMedian() << endl << endl;
	Insert(6);
	cout << GetMedian() << endl << endl;
	Insert(7);
	cout << GetMedian() << endl << endl;
	Insert(0);
	cout << GetMedian() << endl << endl;
	Insert(8);
	cout << GetMedian() << endl << endl;
//5.00 3.50 3.00 3.50 3.00 3.50 4.00 3.50 4.00 "
	return 0;
}