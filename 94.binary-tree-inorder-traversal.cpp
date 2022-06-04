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
  // Morris遍历算法
  vector<int> inorderTraversal(TreeNode *root) {
      vector<int> res;
      while (root) {
	  if (root->left == nullptr) {
	      res.push_back(root->val);
	      root = root->right;
	  } else {
	      TreeNode *temp = root->left;
	      while (temp->right && temp->right != root) {
		  temp = temp->right;
	      }
	      if (temp->right == nullptr) {
		  temp->right = root;
		  root = root->left;
	      } else {
                  temp->right = nullptr;
                  res.push_back(root->val);
                  root = root->right;
              }
          }
      }
      return res;
  }
  /*
  vector<int> inorderTraversal(TreeNode* root) {
      stack<TreeNode*> st;
      vector<int> res;
      while (root||!st.empty()) {
          if(root) {
              st.push(root);
              root = root->left;
          }
          else {
              root = st.top();
              st.pop();
              res.push_back(root->val);
              root = root->right;
          }
      }
      return res;
  }
  */
};
