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

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        //return isEqual(root->left,root->right);
        return check(root->left,root->right);
    }

    /* 递归
    bool isEqual(TreeNode* left,TreeNode* right)
    {
        if((left==NULL)^(right==NULL)) return false;
        if((left==NULL)&&(right==NULL)) return true;
        if(left->val!=right->val) return false;
        if(!isEqual(left->left,right->right)) return false;
        if(!isEqual(left->right,right->left)) return false;
        return true;
    }
    */

    //迭代
    bool check(TreeNode* left, TreeNode* right) {
        stack<TreeNode*> s1,s2;
        s1.push(left);s2.push(right);
        while(!s1.empty()){
            left = s1.top();s1.pop();
            right = s2.top();s2.pop();
            if((left==NULL)^(right==NULL)) return false;
            if((left==NULL)&&(right==NULL)) continue;
            if(left->val!=right->val) return false;
            s1.push(left->left);
            s1.push(left->right);
            s2.push(right->right);
            s2.push(right->left);
        }
        return true;
    }
};
