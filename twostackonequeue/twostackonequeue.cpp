#include <iostream>
#include <stack>

using namespace std;

stack<int> stack1;
stack<int> stack2;

void push(int node){
	while(!stack2.empty()){
		stack1.push(stack2.top());
		stack2.pop();
	}

	stack1.push(node);
}

int pop(){
	while(!stack1.empty()){
		stack2.push(stack1.top());
		stack1.pop();
	}
	int result = -1;
	if(!stack2.empty()){
		result = stack2.top();
		stack2.pop();
	}

	return result;
}

int main()
{

}
