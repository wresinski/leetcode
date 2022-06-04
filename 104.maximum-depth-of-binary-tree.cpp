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
    int maxDepth(TreeNode* root) {
        int res = 0;
        //getMaxDepth(root,1,res);
        res = getMaxDepth(root);
        return res;
    }
    /*
    void getMaxDepth(TreeNode* root, int depth, int& maxDepth)
    {
        if(!root) return;
        if(maxDepth<depth) maxDepth = depth;
        getMaxDepth(root->left,depth+1,maxDepth);
        getMaxDepth(root->right,depth+1,maxDepth);
    }
    */
    int getMaxDepth(TreeNode* root){
        if(!root) return 0;
        return max(getMaxDepth(root->right),getMaxDepth(root->left))+1;
    }
};
