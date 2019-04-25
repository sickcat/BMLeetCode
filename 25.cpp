#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {};
};
class Solution {
public:
	// ListNode* reverseKGroup(ListNode* head, int k) {
	// 	ListNode *tmp = head;
	// 	ListNode **list = new ListNode *[k];
	// 	for(int i = 0; i < k; i++)
	// 		if(tmp == NULL) {
	// 			delete[] list;
	// 			return head;
	// 		}
	// 		else {
	// 			list[i] = tmp;
	// 			if(i != k-1)
	// 				tmp = tmp->next;
	// 		}
	// 	list[0]->next = reverseKGroup(tmp->next, k);
	// 	for(int i = k-1; i > 0; i--) {
	// 		list[i]->next = list[i-1];
	// 	}
	// 	delete[] list;
	// 	return tmp;
	// }
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *tmp = head;
		for(int i = 0; i < k; i++)
			if(tmp == NULL)
				return head;
			else
				tmp = tmp->next;
		ListNode *prev = NULL, *next = NULL;
		ListNode *cur = head;
		for(int i = 0; i < k; i++) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		head->next = reverseKGroup(cur, k);
		return prev;
	}
};
int main() {
	ListNode *a,*b,*c,*d;
	a = new ListNode(1);
	b = new ListNode(2);
	c = new ListNode(3);
	d = new ListNode(4);
	a->val = 1;
	a->next = b;
	b->val = 2;
	b->next = c;
	c->val = 3;
	c->next = d;
	d->val = 4;
	d->next = NULL;
	Solution s;
	ListNode* t = s.reverseKGroup(a, 2);
	while(t) {
		cout << t->val << " ";
		t = t->next;
	}
}