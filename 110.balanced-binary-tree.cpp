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
    bool isBalanced(TreeNode* root) {
        int depth;
        return isBalanced_internal(root,depth);
    }
    bool isBalanced_internal(TreeNode* root, int& depth)
    {
        if(!root) return true;
        int depthL = 0,depthR = 0;
        bool retL = isBalanced_internal(root->left,depthL);
        bool retR = isBalanced_internal(root->right,depthR);
        depth = max(depthL,depthR)+1;
        return retL&&retR&&(abs(depthL-depthR)<=1);
    }
};
