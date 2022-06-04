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
    void reorderList(ListNode* head) {
        ListNode* a = head;
        ListNode* b = head;
        helper(a,b);
    }
    bool helper(ListNode* &a,ListNode* b)
    {
        if(!b) return true;
        if(helper(a,b->next))
        {
            if(a==b||a->next==b) 
            {
                b->next = nullptr;
                return false;
            }
            b->next = a->next;
            a->next = b;
            a = a->next->next;
            return true;
        }
        else return false;
    }
};
