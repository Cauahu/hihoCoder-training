#include <iostream>

using namespace std;

ListNode * findEntry(ListNode * pHead){
	if(pHead == NULL)
		return NULL;
	ListNode *p1 = pHead, *p2 = pHead;
	if(p1->next == NULL)
		return NULL;
	do{
		p1 = p1->next;
		p2 = p2->next->next;
	}while(p1 != p2);
	p1 = pHead;
	while(p1 != p2){
		p1 = p1->next;
		p2 = p2->next;
	}

	return p2;
}
