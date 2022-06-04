class Solution {
public:
    // 二进制
    vector<vector<int>> subsets(vector<int>& nums) {
	int n = 1<<nums.size();
	vector<vector<int>> res;
	for (int i=0; i<n; ++i) {
	    vector<int> temp;
	    for (int j=0; j<nums.size(); ++j) {
	        if (i>>j & 1) {
		    temp.emplace_back(nums[j]);
		}
	    }
	    res.emplace_back(temp);
	}
	return res;
    }
    /*
    // 回溯
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
	vector<int> temp;
	res.emplace_back(temp);
	helper(temp, nums);
	return res;
    }

    void helper(vector<int>& cur,const vector<int>& nums) {
	for (auto iter=nums.begin(); iter!=nums.end(); ++iter) {
	    cur.emplace_back(*iter);
	    res.emplace_back(cur);
	    helper(cur, vector<int>(iter+1, nums.end()));
	    cur.pop_back();
	}
    }
    */
};
