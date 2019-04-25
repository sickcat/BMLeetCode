/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode {
int val;
ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:	
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		// because every time the merge is huge
		// divide and conquer is the best
		// this is the simplest
		if(lists.empty())
			return NULL;
		while(lists.size() > 1) {
			ListNode *a = lists[0];
			ListNode *b = lists[1];
			if(a == NULL) {
				lists.erase(lists.begin());
				continue;
			}
			if(b == NULL) {
				lists.erase(lists.begin() + 1);
				continue;
			}
			ListNode *h = lists[0]->val < lists[1]->val ? lists[0] : lists[1];
			if(lists[0]->val < lists[1]->val)
				a = a->next;
			else
				b = b->next;
			ListNode *n = h;
			while(b != NULL && a != NULL) {
				if(a->val < b->val) {
					n->next = a;
					a = a->next;
					n = n->next;
				} else {
					n->next = b;
					b = b->next;
					n = n->next;
				}
			}
			n->next = a == NULL ? b : a;
			lists.push_back(h);
			lists.erase(lists.begin());
			lists.erase(lists.begin());
		}
		return lists[0];
    }
};
int main() {
	vector<ListNode*> lists;
	for(int i = 0; i < 10; i++) {
		ListNode* p = new ListNode(10-i);
		ListNode* index = p;
		for(int j = 0; j < 0; j++) {
			ListNode *n = new ListNode(j+200);
			index->next = n;
			index = index->next;
		}
		lists.push_back(p);
	}
	Solution s = Solution();
	ListNode* ans = s.mergeKLists(lists);
	while(ans != NULL) {
		cout << ans->val << " ";
		ListNode *tmp = ans;
		ans = ans->next;
		delete tmp;
	}
}