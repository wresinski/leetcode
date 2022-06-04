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
    // 寻找前驱节点
    void flatten(TreeNode* root) {
	TreeNode* cur = root;
	while (cur) {
	    TreeNode* left = cur->left;
	    if (left) {
	        while (left->right) left = left->right;
		left->right = cur->right;
		cur->right = cur->left;
		cur->left = nullptr;
	    }
	    cur = cur->right;
	}
    }
    /*
    // 迭代
    void flatten(TreeNode* root) {
	stack<TreeNode*> st;
	TreeNode* cur = root;
	TreeNode* pre = nullptr;
	while (cur||!st.empty()) {
	    if (cur) {
	        st.push(cur);
		pre = cur;
		TreeNode* right = cur->right;
		cur->right = cur->left;
		cur->left = right;
		cur = cur->right;
	    }
	    else {
	        cur = st.top()->left;
		st.top()->left = nullptr;
		st.pop();
		pre->right = cur;
	    }
	}
    }
    */
    /*
    // 递归
    void flatten(TreeNode* root) {
	preorderTraversal(root);
    }
    TreeNode* preorderTraversal(TreeNode* root) {
	if (!root) return  nullptr;
	TreeNode* right = root->right;
	TreeNode* left = root->left;
	root->left = nullptr;
	if (left) {
	    root->right = left;
	    left = preorderTraversal(left);
	}
	else {
	    left = root;
	}

	if (right) {
	    left->right = right;
	    right = preorderTraversal(right);
	}
	else {
	    right = left;
	}
	return right;
    }
    */
};
