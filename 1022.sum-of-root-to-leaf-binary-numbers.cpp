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
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        if(root) cal(root,0,res);
        return res;
    }
    void cal(TreeNode* node,int sum,int &res)
    {
        sum = sum*2+node->val;
        if(!node->left&&!node->right)
        {
            res += sum;
            return;
        }
        if(node->left) cal(node->left,sum,res);
        if(node->right) cal(node->right,sum,res);
    }
};
