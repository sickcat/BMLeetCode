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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *tmp = head, *pre = NULL;
        while(tmp) {
        	if(tmp->val == val) {
        		if (pre) {
	        		pre->next = tmp->next;
        			delete tmp;
        			tmp = pre->next;        			
        		} else {
        			ListNode *t = tmp;
        			tmp = tmp->next;
        			head = tmp;
        			delete t;
        		}
        	} else {
        		pre = tmp;
        		tmp = tmp->next;
        	}
        }
        return head;
    }
};