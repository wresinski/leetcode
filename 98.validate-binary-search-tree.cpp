/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 中序遍历
    bool isValidBST(TreeNode* root) {
	stack<TreeNode*> st;
	long long pre = (long long)INT_MIN-1;
	while (root || !st.empty()) {
	    if(root) {
		st.push(root);
		root = root->left;
	    }
	    else {
		root = st.top();
		st.pop();
		if(pre>=root->val) return false;
		pre = root->val;
		root = root->right;
	    }
	}
	return true;
    }
    /*
    // 递归
    bool isValidBST(TreeNode* root) {
	return getValue(root->left, INT_MIN, (long long)root->val-1) && getValue(root->right, (long long)root->val+1, INT_MAX);
    }
    bool getValue(TreeNode* node, long long minValue, long long maxValue)
    {
	if(!node) return true;
	if(node->val<minValue || node->val>maxValue) return false;
	return getValue(node->left, minValue, (long long)node->val-1) && getValue(node->right, (long long)node->val+1, maxValue);
    }
    */
};
