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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        cal(root,res,0);
        for(int i=1;i<res.size();i+=2)
        {
            reverse(res[i].begin(),res[i].end());
        }
        return res;
    }
    void cal(TreeNode* node, vector<vector<int>> &vec, int i)
    {
        if(!node) return;
        if(i+1>vec.size()) vec.push_back(vector<int>());
        vec[i].push_back(node->val);
        cal(node->left,vec,i+1);
        cal(node->right,vec,i+1);
    }
};
