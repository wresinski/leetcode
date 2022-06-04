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
    ListNode* partition(ListNode* head, int x) {
	ListNode* small_head = new ListNode;
	ListNode* big_head = new ListNode;
	ListNode* small = small_head;
	ListNode* big = big_head;
	while (head) {
	    if(head->val>=x) {
		big->next = head;
		big = big->next;
	    }
	    else {
		small->next = head;
		small = small->next;
	    }
	    head = head->next;
	}
	big->next = nullptr;
	small->next = big_head->next;
	return small_head->next;
    }
    /*
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = nullptr;
        ListNode* big = nullptr;
        ListNode* smallTmp = nullptr;
        ListNode* bigTmp = nullptr;
        while(head)
        {
            if(head->val<x)
            {
                if(!small)
                {
                    small = head;
                    smallTmp = head;
                }
                else
                {
                    smallTmp->next = head;
                    smallTmp = smallTmp->next;
                }
            }
            else
            {
                if(!big)
                {
                    big = head;
                    bigTmp = head;
                }
                else
                {
                    bigTmp->next = head;
                    bigTmp = bigTmp->next;
                }
            }
            head = head->next;
        }
        if(small) smallTmp->next = big;
        if(big) bigTmp->next = nullptr;
        return small?small:big;
    }
    */
};
