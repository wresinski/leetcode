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
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        calMax(root,maxPath);
        return maxPath;
    }
    int calMax(TreeNode* root, int& maxPath)
    {
        if(!root) return 0;
        int maxPathL = calMax(root->left,maxPath);
        int maxPathR = calMax(root->right,maxPath);
        maxPathL = max(0,maxPathL);
        maxPathR = max(0,maxPathR);
        maxPath = max(maxPath,maxPathL+maxPathR+root->val);
        return max(maxPathL,maxPathR)+root->val;
    }
};
