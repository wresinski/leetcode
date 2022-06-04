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
    // 迭代
    ListNode* swapPairs(ListNode* head) {
	ListNode* dummy = new ListNode(0, head);
	ListNode* pre = dummy;
	while (head&&head->next) {
	    ListNode* next = head->next->next;
	    pre->next = head->next;
	    head->next->next = head;
	    head->next = next;
	    pre = head;
	    head = next;
	}
	return dummy->next;
    }
    /*
    // 递归
    ListNode* swapPairs(ListNode* head) {
	if(!head) return head;
	ListNode* second = head->next;
	if(!second) return head;
	head->next = swapPairs(second->next);
	second->next = head;
	return second;
    }
    */
};
