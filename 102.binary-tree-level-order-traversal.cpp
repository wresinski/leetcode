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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        cal(root,1,res);
        return res;
    }

    void cal(TreeNode* root, int level, vector<vector<int>> &res)
    {
        if(!root) return;
        if(res.size()<level) res.push_back(vector<int>());
        res[level-1].push_back(root->val);
        cal(root->left,level+1,res);
        cal(root->right,level+1,res);
    }
};
