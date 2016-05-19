#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
};
vector<int> printListFromTaillToHead(struct ListNode* head){
	struct ListNode *p = head->next, *p_next = p->next;
	head->next = NULL;
	while(p_next != NULL)
	{
		p->next = head->next;
		head->next = p;
		p = p_next;
		p_next = p->next;
	}	
	p->next = head->next;
	head->next = p;
	
	vector<int > vp;
	p = head->next;
	while(p != NULL)
	{
		vp.push_back(p->val);
		p = p->next;
	}

	return vp;
}


int main(){
	struct ListNode * head = new ListNode;
	head->next = NULL;
	int i = 0;
	while(i < 10){
		struct ListNode *tmp = new ListNode;
		tmp->val = i;
		tmp->next = head->next;
		head->next = tmp;
		i++;
	}
	vector<int> vp = printListFromTaillToHead(head);

	while(!vp.empty()){
		cout << vp.back() << " ";
		vp.pop_back();
	}
	return 0;
}


