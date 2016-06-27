#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool chkLegal(string A)
{
	stack<char> stackA;
	int i = 0, len = A.size();
	for(;i<len;++i)
	{
		if(A[i] == '[' || A[i] == '(' || A[i] == '{')
			stackA.push(A[i]);
		else if(A[i] == ']' || A[i] == ')' || A[i] == '}')
		{
			if(A[i] == ']' && stackA.top() == '['){
				cout << A[i] << " " << stackA.top() << endl;
				stackA.pop();
			}
			else if(A[i] == ')' && stackA.top() == '('){
				cout << A[i] << " " << stackA.top() << endl;
				stackA.pop();
			}
			else if(A[i] == '}' && stackA.top() == '{'){
				cout << A[i] << " " << stackA.top() << endl;
				stackA.pop();
			}
			else 
				return false;
		}			
	}
	if(i != len || stackA.size() > 0){
		cout << stackA.size() << endl;
		return false;
	}
	return true;

}

int main()
{
	string A1 = "{([])}"; //"[a+b*(5-4)]*{x+b+b*{(1+2)}}";
	string A2 = "[a+b*(5-4)]*{x+b+b*(({1+2)}}";
	cout << "A1 is " << (chkLegal(A1)? "Legal" : "Illegal") << endl;
	cout << "A2 is " << (chkLegal(A2)? "Legal" : "Illegal") << endl;
}
