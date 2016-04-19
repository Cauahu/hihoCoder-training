#include<iostream>
#include<stack>

using namespace std;

typedef struct Node{
	int value;
	Node * next;
}LNode,*PNode;

void reverseoutput(PNode LN)
{
	cout << endl;
	PNode tmp = LN->next;
	stack<int> ST;
	while(tmp)
	{
		ST.push(tmp->value);
		tmp = tmp->next;
	}
	while(!ST.empty())
	{
		cout << ST.top() << " ";
		ST.pop();
	}
	cout << endl;
}

void reverse(PNode LN)
{
	PNode tmp = LN->next, ne;
	LN->next = NULL;
	while(tmp)
	{
		ne = tmp->next;
		tmp->next = LN->next;
		LN->next = tmp;
		tmp = ne;
	}
	tmp = LN->next;
	while(tmp)
	{
		cout << tmp->value << " ";
		tmp = tmp->next;
	}
	cout << endl;

}

int main()
{
	PNode LN = new LNode ;
	LN->next = NULL;
	int i = 0;
	while(i < 10)
	{
		PNode tmp = new LNode;
		tmp->value = i++;
		tmp->next = LN->next;
		LN->next = tmp;
	}
	PNode tmp = LN->next;
	while(tmp != NULL)
	{
		cout << tmp->value << " " ;
		tmp = tmp->next;
	}

	reverseoutput(LN);
	reverse(LN);

	return 0;
}

