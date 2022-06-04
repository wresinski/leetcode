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
    vector<double> averageOfLevels(TreeNode* root) {
        avarage.clear();
        count.clear();
        add(root,0);
        for(int i=0;i<avarage.size();++i)
        {
            avarage[i] /= count[i];
        }
        return avarage;
    }
    void add(TreeNode* node,int level)
    {
        if(!node) return;
        if(avarage.size()>=level+1)
        {
            avarage[level] += node->val;
            count[level]++;
        }
        else
        {
            avarage.push_back(node->val);
            count.push_back(1);
        }
        add(node->right,level+1);
        add(node->left,level+1);
    }
private:
    vector<double> avarage;
    vector<int> count;
};
