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
    TreeNode* deleteNode(TreeNode* root, int key) {
	if (!root) return nullptr;
	if (root->val<key) {
	    root->right = deleteNode(root->right, key);
	}
	else if (root->val>key) {
	    root->left = deleteNode(root->left, key);
	}
	else {
	    if (root->left&&root->right) {
		TreeNode* cur = root->right;
		while (cur->left) {
		    cur = cur->left;
		}
		cur->left = root->left;
		return root->right;
	    }
	    else if (root->left) {
		return root->left;
	    }
	    else {
		return root->right;
	    }
	}
	return root;
    }
    /*
    TreeNode* deleteNode(TreeNode* root, int key) {
	TreeNode* dummy = new TreeNode(0, root, nullptr);
	TreeNode* pre = dummy;
	while (root) {
	    if (root->val>key) {
		pre = root;
		root = root->left;
	    }
	    else if (root->val<key) {
		pre = root;
		root = root->right;
	    }
	    else {
		if (root->left) {
		    root->val = getMost(root->left, 1);
		    root->left = deleteNode(root->left, root->val);
		}
		else if (root->right) {
		    root->val = getMost(root->right, 0);
		    root->right = deleteNode(root->right, root->val);
		}
		else {
		    if (pre->right&&pre->right->val==key) pre->right = nullptr;
		    else if (pre->left&&pre->left->val==key) pre->left = nullptr;
		}
		break;
	    }
	}
	return dummy->left;
    }

    int getMost(TreeNode* root, int LR) {
	if (LR==0) {
	    while (root->left) {
	        root = root->left;
	    }
	}
	else {
	    while (root->right) {
	        root = root->right;
	    }
	}
	return root->val;
    }
    */
};
