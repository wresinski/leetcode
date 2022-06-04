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
    // 优先队列
    struct Status {
	int val;
	ListNode* node;
	Status(int v, ListNode* n) : val(v),node(n) {}
	bool operator<(const Status &rhs) const {
	    return val>rhs.val;
	}
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
	ListNode* dummy = new ListNode;
	ListNode* tail = dummy;
	priority_queue<Status> qu;
	for (ListNode* node : lists) {
	    if (node) qu.push(Status(node->val,node));
	}
	while (!qu.empty()) {
	    ListNode* node = qu.top().node;
	    qu.pop();
	    tail->next = node;
	    tail = tail->next;
	    if (node->next) qu.push(Status(node->next->val, node->next));
	}
	return dummy->next;;
    }
    /*
    // 分治
    ListNode* mergeKLists(vector<ListNode*>& lists) {
	int n = lists.size();
	if (n==0) return nullptr;
	for (int i=1; i<n; i<<=1) {
	    int j = 0;
	    while (j+i<n) {
		lists[j] = merge(lists[j], lists[j+i]);
		j = j+i*2;
	    }
	}
	return lists[0];
    }
    ListNode* merge(ListNode* a, ListNode*b) {
	ListNode* dummy = new ListNode;
	ListNode* cur = dummy;
	while (a&&b) {
	    if (a->val<b->val) {
	        cur->next = a;
		a = a->next;
	    }
	    else {
		cur->next = b;
		b = b->next;
	    }
	    cur = cur->next;
	}
	if (a) {
	    cur->next = a;
	}
	if (b) {
	    cur->next = b;
	}
	return dummy->next;
    }
    */
    /*
    ListNode* mergeKLists(vector<ListNode*>& lists) {
	ListNode* dummy = new ListNode;
	ListNode* tail = dummy;
	while (1) {
	    int n = 0;
	    int min_value = INT_MAX;
	    int min_i = -1;
	    for (int i=0; i<lists.size(); ++i) {
		if (lists[i]) {
		    if (min_value>lists[i]->val) {
		        min_value = lists[i]->val;
			min_i = i;
		    }
		}
		else {
		    ++n;
		}
	    }
	    if (n<lists.size()) {
		tail->next = lists[min_i];
		tail = tail->next;
		lists[min_i] = lists[min_i]->next;
	    }
	    else break;
	}
	return dummy->next;
    }
    */
};
