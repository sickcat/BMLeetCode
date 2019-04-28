/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
        	return head;
        int size = 1, tmp = k;
        ListNode *p = head, *tail = head;
        while(tail->next != NULL) {
        	if(tmp-- != 0) {
        		tail = tail->next;
        		size++;
        	} else
        		break;
        }
        if(tail->next == NULL && tmp != 0) {
        	k = k%size;
        	tmp = k;
        	tail = head;
        	while(tail->next != NULL) {
	        	if(tmp-- != 0)
	        		tail = tail->next;
	        	else
	        		break;
	        }
        }
        if(tail == head || k == 0)
        	return head;
        while(tail->next != NULL) {
        	tail = tail->next;
        	p = p->next;
        }
        tail->next = head;
        head = p->next;
        p->next = NULL;
        return head;
    }
};