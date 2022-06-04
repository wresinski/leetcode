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
    /*
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vec1,vec2;
        getVector(root,p,vec1);
        getVector(root,q,vec2);
        int i = 0;
        int length = min(vec1.size(),vec2.size());
        for(;i<length;++i)
        {
            if(vec1[i]!=vec2[i]) break;
        }
        return vec1[i-1];
    }
    bool getVector(TreeNode* root, TreeNode* p, vector<TreeNode*> &vec)
    {
        if(!root) return false;
        vec.push_back(root);
        if(root==p) return true;
        if(getVector(root->left,p,vec)) return true;
        if(getVector(root->right,p,vec)) return true;
        vec.pop_back();
        return false;
    }
    */
    //递归
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	TreeNode* common = nullptr;
	getCommon(root, p, q, common);
	return common;
    }
    bool getCommon(TreeNode* current, TreeNode* p, TreeNode* q, TreeNode* &common) {
	if (common != nullptr)
	    return false;
	if (current == nullptr) return false;
	bool a = current == p || current == q;
	bool b = getCommon(current->right, p, q, common);
	bool c = getCommon(current->left, p, q, common);
	if ((a && b) || (a && c) || (b && c)) {
	    common = current;
	}
	if (a || b || c)
            return true;
        else
            return false;
    }
};
