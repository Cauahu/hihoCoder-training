#include <iostream>

using namespace std;

struct ListNode{
	int value;
	ListNode* next;
};

ListNode* findKthTail(ListNode* plistnode, int k){
	if(plistnode == NULL || k == 0)
		return NULL;
	ListNode* pAhead = plistnode;
	ListNode* pBehind = NULL;
	for(int i=1;i<k;i++)
	{
		if(pAhead->next != NULL)
			pAhead = pAhead->next;
		else
			return NULL;
	}
	pBehind = plistnode;
	while(pAhead->next != NULL)
	{
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}
	return pBehind;
}

int main(){
	int i = 0;
	ListNode* plistnode = new ListNode, *pcur = plistnode, *pnew = NULL;
	plistnode->next = NULL;

	while(i < 10)
	{
		pnew = new ListNode;
		pnew->value = i++;
		pnew->next = pcur->next;
		pcur->next = pnew;
		pcur = pnew;
	}
	pcur = findKthTail(plistnode, 4);
	cout << pcur->value << endl;


}
