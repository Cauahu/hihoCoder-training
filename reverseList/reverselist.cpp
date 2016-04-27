#include <iostream>

using namespace std;

struct ListNode{
	int value;
	ListNode* next;
};

void reverseList(ListNode* list){
	if(list == NULL || list->next->next == NULL)
		return ;
	ListNode* pcur = list->next, *pscur;
	list->next = NULL;
	while(pcur != NULL)
	{
		pscur = pcur->next;
		pcur->next = list->next;
		list->next = pcur;
		pcur = pscur;		
	}
	pcur = list->next;
	while(pcur)
	{
		cout << pcur->value << " ";
		pcur = pcur->next;
	}
	cout << endl;
}

int main(){
	ListNode* plistnode = new ListNode, *pcur = plistnode, *pnew = NULL;
	plistnode->next = NULL;
	int i=0;
	while(i < 10)
	{
		pnew = new ListNode;
		pnew->value = i++;
		cout << i-1 << " " ;
		pnew->next = pcur->next;
		pcur->next = pnew;
		pcur = pnew;
	}
	cout << endl;
	reverseList(plistnode);

}
