/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        cal(root,res,0);
        reverse(res.begin(),res.end());
        return res;
    }
    void cal(TreeNode* node,vector<vector<int>> &vec,int i)
    {
        if(!node) return;
        vector<int> temp;
        if(i+1>vec.size()) vec.push_back(temp);
        vec[i].push_back(node->val);
        cal(node->left,vec,i+1);
        cal(node->right,vec,i+1);
    }
};
