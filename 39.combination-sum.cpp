class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<int> ans;
	sort(candidates.begin(), candidates.end());
	backtrack(ans, candidates, target, 0);
	return res;
    }

    void backtrack(vector<int>& ans, vector<int>& candidates, int target, int i) {
	if (target==0) {
	    res.emplace_back(ans);
	}
	for (int j=i; j<candidates.size(); ++j) {
	    if (candidates[j]<=target) {
	        ans.emplace_back(candidates[j]);
		backtrack(ans, candidates, target-candidates[j], j);
		ans.pop_back();
	    }
	}
    }
};
