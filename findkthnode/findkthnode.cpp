#include <iostream>
struct ListNode{
	int val;
	struct ListNode * next;
};

ListNode * FindKthToTail(ListNode * pListHead, unsigned int k){
	if(pListHead == NULL || k == 0)
		return NULL;
	ListNode * pAhead = pListHead;
	ListNode * pBehind = NULL;
	for(int i=0;i<k-1;++i){
		if(pAhead->next != NULL)
			pAhead = pAhead->next;
		else
			return NULL;
	}
	pBehind = pListHead;
	while(pAhead->next != NULL){
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	} 
	return pBehind;
}

int main()
{
	return 0;
}
