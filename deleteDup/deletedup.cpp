#include <iostream>
using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
};

ListNode* deletedup(ListNode* pHead){
	if(pHead == NULL || pHead->next == NULL)
		return pHead;
	if(pHead->val == pHead->next->val){
		int val = pHead->val;
		ListNode *cur = pHead->next->next;
		delete pHead->next;
		delete pHead;
		while(cur != NULL && cur->val == val){
			ListNode *temp = cur;
			cur = cur->next;
			delete temp;
		}
		return deletedup(cur);
	}
	else
		pHead->next = deletedup(pHead->next);
	return pHead;
}

int main(){
	return 0;
}
