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
    /*
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* a = head;
        ListNode* b = head->next;
	while (b->next) {
	    a = a->next;
	    b = b->next;
	    if (b->next) {
	        b = b->next;
	    }
	}
	b = a->next;
	a->next = nullptr;
	a = head;

        a = sortList(a);
        b = sortList(b);
        a = mergeTwoLists(a,b);
        return a;
    }
    */
    // O(1)空间复杂度
    ListNode* sortList(ListNode* head) {
	int length = 0;
	ListNode* temp = head;
	while (temp) {
	    temp = temp->next;
	    length++;
	}
	ListNode* dummy = new ListNode(0,head);
	for (int sublength=1; sublength<length; sublength*=2) { // 各种不同长度分段
	    ListNode* pre = dummy;
	    ListNode* cur = dummy->next;
	    while (cur) { // 从头开始遍历
		int i = 0;
		ListNode* head1 = cur;
		while (cur&&(++i)<sublength) { // 第一段
		    cur = cur->next;
		}
		ListNode* head2 = nullptr;
		if (cur) {                     // 如果第一段提前结尾
		    head2 = cur->next;
		    cur->next = nullptr;
		}
		cur = head2;
		i = 0;

		while (cur&&(++i)<sublength) { // 第二段
		    cur = cur->next;
		}
		ListNode* next = nullptr;
		if (cur) {                     // 如果第二段提前结尾
		    next = cur->next;
		    cur->next = nullptr;
		}
		pre->next = mergeTwoLists(head1, head2); // 归并

		while (pre->next) {
		    pre = pre->next;
		}
		cur = next;
	    }
	}
	return dummy->next;
    }

    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2)
    {
        ListNode* head = new ListNode;
        ListNode* temp = head;
        while(l1&&l2){
            if(l1->val<l2->val){
                temp->next = l1;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if(l1) temp->next = l1;
        if(l2) temp->next = l2;
        return head->next;
    }
};
