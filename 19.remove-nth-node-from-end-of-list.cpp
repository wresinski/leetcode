/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // 双指针
    ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* dummy = new ListNode(0, head);
	ListNode *slow = dummy, *fast = dummy;
	int count = 0;
	while (fast) {
	    fast = fast->next;
	    if (count==n+1) // 因为fast最终将指向null，所以应该是n+1
		slow = slow->next;
	    else
		count++;
	}
	slow->next = slow->next->next;
	return dummy->next;
    }
    /*
    // 队列法
    ListNode* removeNthFromEnd(ListNode* head, int n) {
	queue<ListNode*> qu;
	ListNode* dummy = new ListNode(0, head);
	qu.push(dummy);
	while (head) {
	    qu.push(head);
	    if (qu.size()>n+1) {
	        qu.pop();
	    }
	    head = head->next;
	}
	ListNode* pre = qu.front();
	qu.pop();
	ListNode* cur = qu.front();
	pre->next = cur->next;
	return dummy->next;
    }
    */
};
