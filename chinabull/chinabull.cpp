#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int calculateMax(vector<int> prices) {
      	if(prices.empty())
           		return 0;
	int sum = 0,temp = 0, len = prices.size();
        	priority_queue<int> pq;
        	for(int b=0,e=1;e<len;++e){
            		if(prices[e-1] > prices[e])
                		b = e;
            		else
             		pq.push(prices[e] - prices[b]);
            	}

            	while(!pq.empty()){
            		cout << pq.top() << " ";
            		pq.pop();
            	}
            	cout << endl;
            	/*
        	sum += pq.top();
       	pq.pop();
        	sum += pq.top();

        	*/
        	return sum;
 }

int main(int argc, char const *argv[])
{
	int a[] = {3,8,5,1,7,8};
	std::vector<int> vec(a, a+6);
	cout << calculateMax(vec) << endl;
	return 0;
}