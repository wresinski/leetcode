class Solution {
public:
    // 二进制
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int n = 1<<nums.size();
	vector<vector<int>> res;
	for (int i=0; i<n; ++i) {
	    vector<int> temp;
	    bool flag = true;
	    for (int j=0; j<nums.size(); ++j) {
		    if (i>>j&1) {
			if (j>0&&nums[j]==nums[j-1]&&!(i>>(j-1)&1)) {
			    flag = false;
			    break;
			}
		    temp.emplace_back(nums[j]);
		}
	    }
	    if (flag) res.emplace_back(temp);
	}
	return res;
    }
    /*
    // 回溯
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<int> temp;
	res.emplace_back(temp);
	helper(temp, nums);
	return res;
    }

    void helper(vector<int>& cur,const vector<int>& nums) {
	for (auto iter=nums.begin(); iter!=nums.end(); ++iter) {
	    if (iter!=nums.begin()&&*(iter-1)==*iter) continue;
	    cur.emplace_back(*iter);
	    res.emplace_back(cur);
	    helper(cur, vector<int>(iter+1, nums.end()));
	    cur.pop_back();
	}
    }
    */
};
