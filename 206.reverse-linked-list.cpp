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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* res = helper(head);
        head->next = nullptr;
        return res;

        //ListNode* current = head;
        //ListNode* last = nullptr;
        //ListNode* next = nullptr;
        //while(current)
        //{
        //    next = current->next;
        //    current->next = last;
        //    last = current;
        //    current = next;
        //}
        //return last;
    }
    ListNode* helper(ListNode* head)
    {
        if(!head->next) return head;
        ListNode* res = helper(head->next);
        head->next->next = head;
        return res;
    }
};
