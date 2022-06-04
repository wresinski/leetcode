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
    string tree2str(TreeNode* t) {
        string res;
        if(!t) return res;
        res += to_string(t->val);
        string left = tree2str(t->left);
        string right = tree2str(t->right);
        if(!left.empty()||!right.empty()) res = res+'('+left+')';
        if(!right.empty()) res = res+'('+right+')';
        return res;
    }
};
