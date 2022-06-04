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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* left = dummy;
	for(int i=1;i<m;++i) {
	    left = left->next;
	}
	ListNode* right = left->next;
	ListNode* current = right;
	ListNode* temp;
	for(int i=m;i<=n;++i) {
	    temp = current->next;
	    current->next = left->next;
	    left->next = current;
	    current = temp;
	}
	right->next = temp;
	return dummy->next;
    }
    /*
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //Solution1
        if(m==n) return head;
        ListNode* left1 = head;
        if(m>1)
        {   
            for(int i=0;i<m-2;++i)
            {
                left1 = left1->next;
            }
        }
        else
        {
            left1 = new ListNode(0);
            left1->next = head;
        }
        ListNode* left2 = left1->next;
        
        ListNode* current = left2;
        ListNode* next = current->next;
        for(int i=m;i<n;++i)
        {
            ListNode* temp = next->next;
            next->next = current;
            current = next;
            next = temp;
        }
        left1->next = current;
        left2->next = next;
        if(m<=1) head = left1->next;
        return head;

        //Solution2
        ListNode* left = head;
        for(int i=0;i<m-1;++i)
        {
           left = left->next;
        }
        exchange(left,m-1,n-1);
        return head;
    }
    ListNode* exchange(ListNode* left, int m, int n)
    {
        int temp = left->val;
        ListNode* right = left;
        if(n-m<=2)
        {
            for(int i=0;i<n-m;++i)
            {
                right = right->next;
            }
        }
        else
        {
            right = exchange(left->next,m+1,n-1)->next;
        }
        left->val = right->val;
        right->val = temp;
        return right;
    }
    */
};
