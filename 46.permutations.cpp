class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
	backtrack(nums, 0);
	return res;
    }
    void backtrack(vector<int> &nums, int i) {
	if (i==nums.size()) {
	    res.emplace_back(nums);
	}
	for (int j=i; j<nums.size(); ++j) {
	    swap(nums[i], nums[j]);
	    backtrack(nums, i+1);
	    swap(nums[i], nums[j]);
	}
    }
    /*
    vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> res;
	if (nums.size()==1) {
	    res.push_back({nums[0]});
	    return res;
	}
	for (int i=0; i<nums.size(); ++i) {
	    vector<int> temp1 = nums;
	    temp1.erase(temp1.begin()+i);
	    vector<vector<int>> ret = permute(temp1);
	    for (int j=0; j<ret.size(); ++j) {
	        vector<int> temp2;
		temp2.emplace_back(nums[i]);
		temp2.insert(temp2.end(), ret[j].begin(), ret[j].end());
		res.emplace_back(temp2);
	    }
	}
	return res;
    }
    */
};
