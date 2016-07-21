#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
};

ListNode* partition(ListNode* pHead, int x){
	if(pHead == NULL)
		return NULL;
	ListNode *pbegin = new ListNode, *pend = new ListNode;
	ListNode *pb = pbegin, *pe = pend, *p = pHead;
	while(p != NULL)
	{
		if(p->val < x){
			pb->next = p;
			pb = pb->next;
		}
		else{
			pe->next = p;
			pe = pe->next;
		}
		p = p->next;
	}
	pb->next = pend->next;
	pe->next = NULL;

	return pbegin->next;
}

int main()
{
	int a[] = {12,34,56,78,90,9,24,68,47};
	ListNode * pHead = new ListNode, *p = pHead;
	pHead->val = 0;
	pHead->next = NULL;
	for(int i=0;i<9;++i)
	{
		p->next = new ListNode;
		p->next->val = a[i];
		p->next->next = NULL;
		p = p->next;
	}
	p = pHead ;
	while(p != NULL){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	p = partition(pHead, 50) ;
	while(p != NULL){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	return 0;
}
