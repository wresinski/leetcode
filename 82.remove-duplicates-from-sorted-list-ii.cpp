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
    ListNode* deleteDuplicates(ListNode* head) {
	ListNode* dummy = new ListNode(-101);
	dummy->next = head; 
	ListNode* current = dummy;
	while (current&&current->next&&current->next->next) {
	    if(current->next->val==current->next->next->val) {
		int x = current->next->val;
		while (current->next&&current->next->val==x) {
		    current->next = current->next->next;
		}
	    }
	    else {
		current = current->next;
	    }
	}
        return dummy->next;
    }
    /*
    ListNode* deleteDuplicates(ListNode* head) {
        while(1)
        {
            bool b = false;
            ListNode* current = head;
            if(!current) return head;
            while(current->next)
            {
                if(current->val==current->next->val) 
                {
                    current = current->next;
                    b = true;
                }
                else
                {
                    break;
                }
            }
            if(b) head = current->next;
            else break;
        }

        ListNode* pre = head;
        while(1)
        {
            bool b = false;
            ListNode* current = pre->next;
            if(!current) break;
            while(current->next)
            {
                if(current->val==current->next->val)
                {
                    current = current->next;
                    b = true;
                }
                else
                {
                    break;
                }
            }
            if(b) pre->next = current->next;
            else pre = pre->next;
        }
        return head;
    }
    */
};
