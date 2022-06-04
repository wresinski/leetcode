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
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next&&fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        temp = reverseList(temp);
        fast = head;
        ListNode* temp2 = temp;
        bool b = true;
        while(temp)
        {
            if(temp->val!=fast->val)
            {
                b = false;
                break;
            }
            temp = temp->next;
            fast = fast->next;
        }
        temp2 = reverseList(temp2);
        slow->next = temp2;
        return b;
    }
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* current = head;
        while(current)
        {
            ListNode* next = current->next;
            current->next = pre;
            pre = current;
            current = next;
        }
        return pre;
    }
};
