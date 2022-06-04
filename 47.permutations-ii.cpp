class Solution {
public:
    vector<vector<int>> res;
    vector<int> v;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
	v.resize(nums.size());
	sort(nums.begin(), nums.end());
	vector<int> temp;
	backtrack(nums, temp, 0);
	return res;
    }

    void backtrack(vector<int> &nums, vector<int> &temp, int i) {
	if (i==nums.size()) {
	    res.emplace_back(temp);
	}
	for (int j=0; j<nums.size(); ++j) {
	    if (v[j]!=0||(j>0&&nums[j]==nums[j-1]&&v[j-1]==0)) continue;
	    temp.emplace_back(nums[j]);
	    v[j] = 1;
	    backtrack(nums, temp, i+1);
	    v[j] = 0;
	    temp.pop_back();
	}
    }
};
