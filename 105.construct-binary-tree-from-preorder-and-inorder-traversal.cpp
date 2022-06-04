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
    // 迭代
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	int n = preorder.size();
	stack<TreeNode*> st;
	int i = 0;
	int j = 0;
	TreeNode* root = new TreeNode(preorder[i]);
	st.push(root);
	++i;
	TreeNode* pre = nullptr; 
	while (i<n) {
	    if (!st.empty()&&st.top()->val==inorder[j]) {
		pre = st.top();
		st.pop();
		++j;
	    }
	    else {
		if (pre) {
		    TreeNode* temp = new TreeNode(preorder[i]);
		    pre->right = temp;
		    st.push(temp);
		    pre = nullptr;
		}
		else {
		    TreeNode* temp = new TreeNode(preorder[i]);
		    st.top()->left = temp;
		    st.push(temp);
		}
		++i;
	    } 
	}
	return root;
    }
    /*
    // 递归
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size()==0) return nullptr;
	TreeNode* root = new TreeNode(preorder[0]);
	auto iter = find(inorder.begin(), inorder.end(), preorder[0]);
	vector<int> inorder_left(inorder.begin(), iter);
	vector<int> inorder_right(iter+1, inorder.end());
	vector<int> preorder_left(preorder.begin()+1, preorder.begin()+1+inorder_left.size());
	vector<int> preorder_right(preorder.begin()+1+inorder_left.size(), preorder.end());
	root->left = buildTree(preorder_left, inorder_left);
	root->right = buildTree(preorder_right, inorder_right);
	return root;
    }
    */
};
