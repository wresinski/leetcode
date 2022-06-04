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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* a = head;
        ListNode* b = head;
        while(a->next&&a->next->next)
        {
            a = a->next->next;
            b = b->next;
            if(a==b) return true;
        }
        return false;
    }
};
