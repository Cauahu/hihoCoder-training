#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() != popV.size())
            return false;
		if(pushV.size() == 1)
			return pushV[0] == popV[0];
			

        stack<int> as_stack;
        int pushcur = 1, popcur = 0;
        bool result = true;
		as_stack.push(pushV[0]);
		while(popcur < popV.size()){
            while(pushcur < pushV.size() && as_stack.top() != popV[popcur]){
                as_stack.push(pushV[pushcur++]);    
            }
            if(as_stack.top() != popV[popcur]){
                result = false;
                break;
            }
			cout << as_stack.top() << " ";
            as_stack.pop();
            popcur++;
        }
		cout << endl;
		return result;
    }

int main(){
	int a[] = {1,2,3,4,5}, b[] = {4,5,3,2,1}, c[] = {4,3,5,1,2};
	vector<int> pushV(a, a+5), popV1(b, b+5), popV2(c, c+5);
	cout << (IsPopOrder(pushV, popV1)? "ture" : "false") << endl;
	cout << (IsPopOrder(pushV, popV2)? "ture" : "false") << endl;
	return 0;
}
