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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        bool bCycle = false;
        ListNode* a = head;
        ListNode* b = head;
        while(a->next&&a->next->next)
        {
            a = a->next->next;
            b = b->next;
            if(a==b) 
            {
                bCycle = true;
                break;
            }
        }
        if(!bCycle) return nullptr;
        a = head;
        while(a!=b)
        {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};
