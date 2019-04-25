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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
        	return	head;
        ListNode *a = head, *b = head->next;
        a->next = swapPairs(b->next);
        b->next = a;
        return b;
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
	ListNode* t = s.swapPairs(a);
	while(t) {
		cout << t->val << " ";
		t = t->next;
	}
}