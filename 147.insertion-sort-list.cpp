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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode* pre = head;
        while(pre->next)
        {
            ListNode* current = pre->next;
            if(pre->val<=current->val) 
            {
                pre = pre->next;
                continue;
            }
            pre->next = current->next;
            ListNode* temp = dummy;
            while(temp->next->val<=current->val) temp = temp->next;
            current->next = temp->next;
            temp->next = current;
        }
        return dummy->next;
    }
};
