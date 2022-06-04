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
    // 动态规划2
    vector<TreeNode*> generateTrees(int n) {
	vector<TreeNode*> cur;
	vector<TreeNode*> pre(1,new TreeNode(1));

	TreeNode* dummy = new TreeNode(0);
	for (int i=2; i<=n; ++i) {
	    for (auto iter=pre.begin(); iter!=pre.end(); ++iter) {
		TreeNode* root = *iter;
		TreeNode* temp = root;
		int nc = 1;
		while (temp) {
		    temp = temp->right;
		    nc++;
		}
		while (nc) {
		    nc--;
		    temp = copyTree(root);
		    dummy->right = temp;
		    temp = dummy;
		    for (int j=0; j<nc; ++j) {
			temp = temp->right;
		    }
		    TreeNode* node = new TreeNode(i);
		    node->left = temp->right;
		    temp->right = node;
		    cur.emplace_back(dummy->right);
		}
	    }
	    pre = cur;
	    cur.clear();
	}
	return pre;
    }

    TreeNode* copyTree(TreeNode* root) {
	if (!root) return nullptr;
	TreeNode* res = new TreeNode(root->val);
	res->left = copyTree(root->left);
	res->right = copyTree(root->right);
	return res;
    }
    
    /*
    // 动态规划
    vector<TreeNode*> generateTrees(int n) {
	vector<vector<vector<TreeNode*>>> dp(n+2, vector<vector<TreeNode*>>(n+2, {nullptr}));
	for (int i=1; i<=n; ++i) {
	    dp[i][i] = {new TreeNode(i)};
	}
	for (int j=2; j<=n; ++j) {
	    int start = 1;
	    int end = j;
	    while (end<=n) {
		dp[start][end].clear();
		for (int i=start; i<=end; ++i) {
		    vector<TreeNode*> &left = dp[start][i-1];
		    vector<TreeNode*> &right = dp[i+1][end];
		    for (auto iterl=left.begin(); iterl!=left.end(); ++iterl) {
			for (auto iterr=right.begin(); iterr!=right.end(); ++iterr) {
			    TreeNode* root = new TreeNode(i);
			    root->left = *iterl;
			    root->right = *iterr;
			    dp[start][end].emplace_back(root);
			}
		    }
		}
		start++;
		end++;
	    }
	}
	return dp[1][n];
    }
    */
    /*
    // 分治法
    vector<TreeNode*> generateTrees(int n) {
	return generateTrees(1,n);
    }

    vector<TreeNode*> generateTrees(int start, int end) {
	if (start>end) {
	    return {nullptr};
	}
	vector<TreeNode*> res;
	for (int i=start; i<=end; ++i) {
	    vector<TreeNode*> left = generateTrees(start, i-1);
	    vector<TreeNode*> right = generateTrees(i+1, end);

	    for (auto iterl=left.begin(); iterl!=left.end(); ++iterl) {
		for (auto iterr=right.begin(); iterr!=right.end(); ++iterr) {
		    TreeNode* root = new TreeNode(i);
		    root->left = *iterl;
		    root->right = *iterr;
		    res.emplace_back(root);
		}
	    }
	}
	return res;
    }
    */
};
